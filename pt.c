#include <pointcloud.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  PtcPointCloud ptc = PtcSafeOpenPointCloudFile(argv[1]);
  int success = 1;
  float p[3];
  float n[3];
  float r;
  float *d;
  int npoints = 0, nvars = 0, datasize = 0;
  char **vartypes = NULL, **varnames = NULL;
  PtcGetPointCloudInfo(ptc, "npoints", &npoints);
  PtcGetPointCloudInfo(ptc, "nvars", &nvars);
  PtcGetPointCloudInfo(ptc, "vartypes", &vartypes);
  PtcGetPointCloudInfo(ptc, "varnames", &varnames);
  PtcGetPointCloudInfo(ptc, "datasize", &datasize);
  d = malloc(sizeof(float) * datasize);
  for(int i=0; i<npoints; i++) {
  	if(PtcReadDataPoint(ptc, p, n, &r, d) == 0) {
  		break;
  	} else {
  		printf("%f,%f,%f,%f,%f,%f,%f", p[0], p[1], p[2], n[0], n[1], n[2], r);
      printf(",%d,%d", datasize, nvars);
      if (datasize > 0) {
        for(int n=0;n<nvars; n++) {
          printf(",%s,%s",varnames[n],vartypes[n]);
        }
        for(int v=0;v<datasize;v++) {
          printf(",%f",d[v]);
        }
      }
      printf("\n");
  	}
  }
  return 0;
}
