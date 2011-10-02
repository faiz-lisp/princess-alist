# -*- mode: Python; tab-width: 2; indent-tabs-mode: nil -*-
# vim: set filetype=python tabstop=2 shiftwidth=2 softtabstop=2 expandtab:

{
  'target_defaults': {
    'conditions': [
      ['OS=="linux" or OS=="mac"', {
        'cflags': [
          '-Wall'
        ]
      }],
      ['OS=="win"', {
        'defines': [
          'WIN32'
        ],
        'msvs_settings': {
          'VCCLCompilerTool': {
            'WarningLevel': '4'
          }
        }
      }]
    ],

    'configurations': {
      'Debug': {
        'defines': [
          '_DEBUG'
        ],
        'conditions': [
          ['OS!="win"', {
            'cflags': [
              '-g'
            ]
          }, {
            'msvs_configuration_attributes': {
              'CharacterSet': '1'
            },
            'msvs_settings': {
              'VCCLCompilerTool': {
                'Optimization': '0',

                'conditions': [
                  ['library=="shared_library"', {
                    'RuntimeLibrary': '3'  # /MDd
                  }, {
                    'RuntimeLibrary': '1'  # /MTd
                  }]
                ]
              },
              'VCLinkerTool': {
                'LinkIncremental': '2'
              }
            }
          }],
        ]
      },

      'Release': {
        'conditions': [
          ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
            'cflags': [
              '-O3'
            ]
          }],
          ['OS=="win"', {
            'msvs_configuration_attributes': {
              'CharacterSet': '1'
            },
            'msvs_settings': {
              'VCCLCompilerTool': {
                'Optimization': '2',

                'conditions': [
                  ['library=="shared_library"', {
                    'RuntimeLibrary': '2'  # /MD
                  }, {
                    'RuntimeLibrary': '0'  # /MT
                  }]
                ]
              }
            }
          }],
          ['OS=="mac"', {
            'xcode_settings': {
              'GCC_OPTIMIZATION_LEVEL': '3',

              # -fstrict-aliasing. Mainline gcc enables
              # this at -O2 and above, but Apple gcc does
              # not unless it is specified explicitly.
              'GCC_STRICT_ALIASING': 'YES'
            }
          }]
        ]
      }
    }
  },

  'targets': [
    {
      'target_name': '(>>>FILE_SANS<<<)',
      'type': '',  # executable, <(library)
      # 'dependencies': [
      # ],
      # 'defines': [
      # ],
      # 'include_dirs': [
      # ],
      'sources': [
      ],
      'conditions': [
        ['OS!="win"', {
          'ldflags': [
            '-'
          ]
        }, {
        }]
      ]
    }
  ]
}
