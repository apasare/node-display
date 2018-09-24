{
  "targets": [
    {
      "target_name": "display",
      "variables": {
      },
      "sources": [
        "src/display.cc",
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "libraries": [
      ],
      "cflags_cc": [
      ]
    }
  ]
}