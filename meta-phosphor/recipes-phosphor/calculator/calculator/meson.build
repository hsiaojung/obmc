project('calculator', 'cpp', 'c',
    default_options: [
      'buildtype=debugoptimized',
      'cpp_std=c++20',
      'warning_level=3',
      'werror=true',
      'tests=' + (meson.is_subproject() ? 'disabled' : 'auto'),
      'examples=' + (meson.is_subproject() ? 'disabled' : 'auto'),
    ],
    version: '1.0.0',
    meson_version: '>=0.57.0',
)

sdbusplus_dep = dependency('sdbusplus')
#sdbusplusplus_prog = find_program('sdbus++', native: true)
#sdbuspp_gen_meson_prog = find_program('sdbus++-gen-meson', native: true)
sdbusplusplus_depfiles = files()
if sdbusplus_dep.type_name() == 'internal'
  sdbusplusplus_depfiles = subproject('sdbusplus').get_variable('sdbusplusplus_depfiles')
endif




#libsystemd_pkg = dependency('libsystemd')
#libsystemd_pkg = dependency('systemd')

#systemd_dep = dependency('systemd').get_variable(pkgconfig: 'systemdsystemunitdir'))
systemd_dep = dependency('systemd')

python = import('python')
python_bin = python.find_installation('python3', modules:['inflection', 'yaml', 'mako'])

boost_compile_args = [
    '-DBOOST_ASIO_DISABLE_THREADS',
    '-DBOOST_ALL_NO_LIB',
    '-DBOOST_SYSTEM_NO_DEPRECATED',
    '-DBOOST_ERROR_CODE_HEADER_ONLY',
    '-DBOOST_COROUTINES_NO_DEPRECATION_WARNING',
]

boost_dep = declare_dependency(
    dependencies: dependency('boost', required: false),
    compile_args: boost_compile_args)

subdir('tools')


install_subdir(
    'include/sdbusplus',
    install_dir: get_option('includedir'),
    strip_directory: false,
)

subdir('example')

