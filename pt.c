#include <pointcloud.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  PtcPointCloud ptc = PtcSafeOpenPointCloudFile(argv[1]);
  int success = 1;
  float p[3];
  float n[3];
  float r;
  float d[16];
  int npoints = 0;
  PtcGetPointCloudInfo(ptc, "npoints", &npoints);
  for(int i=0; i<npoints; i++) {
  	if(PtcReadDataPoint(ptc, p, n, &r, d) == 0) {
  		break;
  	} else {
  		printf("%f,%f,%f,%f,%f,%f,%f\n", p[0], p[1], p[2], n[0], n[1], n[2], r);
  	}
  }
  return 0;
}
