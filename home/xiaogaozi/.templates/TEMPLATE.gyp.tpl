# -*- Mode: Python; tab-width: 2; indent-tabs-mode: nil -*-
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
        'cflags': [
          '/Wall'
        ]
      }]
    ]
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
      # 'conditions': [
      #   ['OS=="linux" or OS=="mac"', {
      #     'ldflags': [
      #       '-'
      #     ]
      #   }],
      #   ['OS=="win"', {
      #     'ldflags': [
      #       '-'
      #     ]
      #   }]
      # ]
    }
  ]
}