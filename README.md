# libdawgdic

Pure C bindings to the dawgdic C++ library. This library allows you to
use the DAWG data structure in your C applications and easily implement
DAWGs in your favourite scripting language via FFI.

## Building

```shell
git clone https://github.com/ustalov/libdawgdic.git
mkdir libdawgdic/build
cd libdawgdic/build
cmake ..
make
```

## Installation

```shell
sudo make install
```

After that you may consider two new files in your system:
`CMAKE_INSTALL_PREFIX/lib/libdawgdic.so` and
`CMAKE_INSTALL_PREFIX/include/dawgdic/cdawgdic.h`.

## Contributing

1. Fork it;
2. Create your feature branch (`git checkout -b my-new-feature`);
3. Commit your changes (`git commit -am 'Added some feature'`);
4. Push to the branch (`git push origin my-new-feature`);
5. Create new Pull Request.

## Copyright

Copyright (c) 2013, [Dmitry Ustalov](http://eveel.ru). See LICENSE for details.

### dawgdic

The libdawgdic library uses the C++ headers of the original
[dawgdic](http://code.google.com/p/dawgdic/) library.

Copyright (c) 2009-2012, Susumu Yata, All rights reserved.
