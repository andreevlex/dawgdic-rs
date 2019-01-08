# libdawgdic

Pure C bindings to the dawgdic C++ library. This library allows you to
use the DAWG data structure in your C applications and easily implement
DAWGs in your favourite scripting language via FFI.

## Installation

There are six simple steps to compile and install libdawgdic into your
system.

1. Clone it with `git clone https://github.com/dmchk/libdawgdic.git`
2. Prepare the build directory with `mkdir libdawgdic/build`
3. Configure it with `cd libdawgdic/build && cmake ..`
4. Compile it with `make`
5. Install it with `sudo make install`
6. Reconfigure your runtime bindings with `sudo ldconfig`, if necessary.

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
