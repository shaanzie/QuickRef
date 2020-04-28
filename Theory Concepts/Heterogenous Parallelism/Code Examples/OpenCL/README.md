# OpenCL

To run, ensure you have a g++ compiler with OpenCL support.

```
module load cudatoolkit
g++ <filename> -lOpenCL -o <filename>.out
./<filename>.out
```

The files are
- Vector addition
- Matrix multiplication