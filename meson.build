project('sdeventplus', 'cpp',
        version: '0.1', meson_version: '>=0.50.0',
        default_options: [
          'warning_level=3',
          'werror=true',
          'cpp_std=c++17'
        ])

subdir('src')

build_tests = get_option('tests')
build_examples = get_option('examples')

if build_examples
  subdir('example')
endif
if not build_tests.disabled()
  subdir('test')
endif
