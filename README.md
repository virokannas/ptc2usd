# ptc2usd
Converts point cloud files to usd files.

## 2D ASCII-Graphical representation of what's happening
```
     .                         .
  ....    .       ->        ....    .
        .                         .
```


## Usage:

```
python ptc2usd.py <in_file.(ptc|json)> <out_file.usd[a]>
```

(out_file can also be -, in which case there will be an usda output to stdout)

The script supports two formats:
* Pixar's PTC
* Houdini JSON point output

Please note that you need to have [Pixar's USD](https://github.com/pixarAnimationStudios/USD) and its python modules in PATH and PYTHONPATH, respectively.

If running against PTC files, the script will try to locate a RenderManProServer installation and use the prman library there. If your installation location is unusual, use the LD_LIBRARY_PATH or DYLD_LIBRARY_PATH environment variable to include that location. Also, if one is already specified, no locating will be done.


## Why?

Since no one asked this, I feel obligated to answer; just because.

PTC is an old format and mainly used with RenderMan (since it's originally a Pixar in-house format) but I'm sure there's a lot of legacy stuff still out there. My hope is that small tools like this will help in the transition to USD.

Modern tools, pretty much all of them, already can export point objects as USD.

## Roadmap:

* Include attributes (color, size, custom data)
* Support turning per-frame ptc files into time slices
