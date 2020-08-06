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

## Why?

Since no one asked this, I feel obligated to answer; just because.

PTC is an old format and mainly used with RenderMan (since it's originally a Pixar in-house format) but I'm sure there's a lot of legacy stuff still out there. My hope is that small tools like this will help in the transition to USD.

Modern tools, pretty much all of them, already can export point objects as USD.

## Roadmap:

* Include attributes (color, size, custom data)
* Support turning per-frame ptc files into time slices
