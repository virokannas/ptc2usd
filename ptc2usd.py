from pxr import Usd, UsdGeom, Gf
import tempfile
import json
import sys
import os


def _dedupe_ptc(data):
    ret = {}
    # only lists? skip
    all_lists = True
    for a in data:
        if not isinstance(a, list):
            all_lists = False
    if all_lists:
        ret = []
        for a in data:
            ret.append(_dedupe_ptc(a))
        return ret

    for i, a in enumerate(data):
        if i % 2 == 0:
            k = a
        if i % 2 == 1:
            if isinstance(a, list) and k not in ["tuples", "arrays"]:
                ret[k] = _dedupe_ptc(a)
            else:
                ret[k] = a
    return ret


class PTCParser(object):
    def __init__(self, path):
        self.path = path
        self._data = {}

    def parse(self):
        with open(self.path) as f:
            tmp_data = json.load(f)
            # handle data tuples
            self._data = _dedupe_ptc(tmp_data)
        if "attributes" in self._data:
            self.attributes = self._data["attributes"]

    def write_usd(self, path):
        use_stdout = False
        if path == "-":
            use_stdout = True
            std_f, path = tempfile.mkstemp("{}.usda".format(os.path.basename(self.path).split(".")[0]))
        stage = Usd.Stage.CreateNew(path)
        xform = UsdGeom.Xform.Define(stage, '/points')
        for p_attr in self.attributes.get("pointattributes", []):
            if p_attr[0]["name"] == "P":
                values = p_attr[1]["values"]["tuples"]
                pts = UsdGeom.Points(xform)
                attr = pts.CreatePointsAttr()
                all_points = []
                for p in values:
                    all_points.append(Gf.Vec3f(p[0],p[1],p[2]))
                attr.Set(all_points)
        stage.GetRootLayer().Save()
        if use_stdout:
            with open(path, "r") as f:
                for line in f:
                    sys.stdout.write(line)


if len(sys.argv)<3:
    print("USAGE:\n\tptc2usd <in_file.ptc> <out_file.usd[a]>")
    sys.exit(0)

pp = PTCParser(sys.argv[1])
pp.parse()
pp.write_usd(sys.argv[2])
