#!/usr/bin/env ruby

begin
  require 'ffi'
rescue LoadError
  require 'rubygems'
  require 'ffi'
end

module Dawgdic
  extend FFI::Library
  ffi_lib 'build/libdawgdic.so'

  attach_function :dawgdic_dawg_new, [], :pointer
  attach_function :dawgdic_dawg_free, [:pointer], :void

  attach_function :dawgdic_builder_new, [], :pointer
  attach_function :dawgdic_builder_free, [:pointer], :void
  attach_function :dawgdic_builder_insert, [:pointer, :string], :bool
  attach_function :dawgdic_builder_insert2, [:pointer, :string, :int], :bool
  attach_function :dawgdic_builder_insert3, [:pointer, :string, :uint, :int], :bool
  attach_function :dawgdic_builder_size, [:pointer], :uint
  attach_function :dawgdic_builder_finish, [:pointer, :pointer], :bool
  attach_function :dawgdic_builder_clear, [:pointer], :void

  attach_function :dawgdic_dictionary_new, [], :pointer
  attach_function :dawgdic_dictionary_free, [:pointer], :void
  attach_function :dawgdic_dictionary_clear, [:pointer], :void
  attach_function :dawgdic_dictionary_fread, [:pointer, :string], :bool
  attach_function :dawgdic_dictionary_fwrite, [:pointer, :string], :bool
  attach_function :dawgdic_dictionary_contains, [:pointer, :string], :bool
  attach_function :dawgdic_dictionary_find, [:pointer, :string], :int
  attach_function :dawgdic_dictionary_size, [:pointer], :uint
  attach_function :dawgdic_dictionary_total_size, [:pointer], :uint
  attach_function :dawgdic_dictionary_file_size, [:pointer], :uint

  attach_function :dawgdic_dictionary_builder_build, [:pointer, :pointer], :bool
end

builder = Dawgdic.dawgdic_builder_new
p Dawgdic.dawgdic_builder_size(builder)
p Dawgdic.dawgdic_builder_insert(builder, 'zaebis')
p Dawgdic.dawgdic_builder_insert2(builder, 'zaebis228', 228)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 359)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 228)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 359)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 359)
Dawgdic.dawgdic_builder_clear(builder)
p Dawgdic.dawgdic_builder_size(builder)
p Dawgdic.dawgdic_builder_insert(builder, 'zaebis')
p Dawgdic.dawgdic_builder_insert2(builder, 'zaebis228', 228)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 359)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 228)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 359)
p Dawgdic.dawgdic_builder_insert3(builder, 'zaebis228359', 12, 359)
p Dawgdic.dawgdic_builder_size(builder)

dawg = Dawgdic.dawgdic_dawg_new
Dawgdic.dawgdic_builder_finish(builder, dawg)

dict = Dawgdic.dawgdic_dictionary_new
Dawgdic.dawgdic_dictionary_builder_build(dawg, dict)

Dawgdic.dawgdic_dictionary_fwrite(dict, 'test.dic')
Dawgdic.dawgdic_dictionary_clear(dict)
Dawgdic.dawgdic_dictionary_fread(dict, 'test.dic')
Dawgdic.dawgdic_dictionary_fwrite(dict, 'test.dic')

Dawgdic.dawgdic_dictionary_contains(dict, 'zaebis22835') == false
Dawgdic.dawgdic_dictionary_find(dict, 'zaebis228359') == 228

Dawgdic.dawgdic_dictionary_free(dict)
Dawgdic.dawgdic_dawg_free(dawg)
Dawgdic.dawgdic_builder_free(builder)
