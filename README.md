# ptc2usd
Converts ptc files to usd files.

## 2D ASCII-Graphical representation of what's happening
```
     .                         .
  ....    .       ->        ....    .
        .                         .
```


## Usage:

```
python ptc2usd.py <in_file.ptc> <out_file.usd[a]>
```

(out_file can also be -, in which case there will be an usda output to stdout)

Please note that you need to have [Pixar's USD](https://github.com/pixarAnimationStudios/USD) and its python modules in PATH and PYTHONPATH, respectively.

## Roadmap:

* Include attributes (color, size, custom data)
* Support turning per-frame ptc files into time slices
