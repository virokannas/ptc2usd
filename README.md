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

If you need to run this on a different platform (the current binaries are for MacOS 10.15 and CentOS 7), just compile the pt.c into a matching file under bin/. The name is created using sys.platform: ```"{}_pt".format(sys.platform)``` so depending on your Linux distribution and python version it may be linux_pt or linux2_pt.

To compile, just supply your desired C compiler with the library / include paths and libraries to link with, examples:
```shell
# CentOS 7
gcc -o bin/linux_pt -I/opt/pixar/RenderManProServer-23.2/include -std=c99 -L/opt/pixar/RenderManProServer-23.2/lib -lprman -lpxrcore pt.c

# MacOS 10.15 (note that clang doesn't need the -std=c99 flag by default)
gcc -o bin/darwin_pt -I/Applications/Pixar/RendermanProServer-23.2/include -L/Applications/Pixar/RendermanProServer-23.2/lib -lprman -lpxrcore pt.c
```

## Why?

Since no one asked this, I feel obligated to answer; just because.

PTC is an old format and mainly used with RenderMan (since it's originally a Pixar in-house format) but I'm sure there's a lot of legacy stuff still out there. My hope is that small tools like this will help in the transition to USD.

Modern tools, pretty much all of them, already can export point objects as USD.

## Roadmap:

* Include attributes (color, size, custom data)
* Support turning per-frame ptc files into time slices
