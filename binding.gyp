{
  "targets": [
    {
      "target_name": "display",
      "conditions": [
        ['OS == "win"', {
          "sources": [
            "src/display.cc",
          ],
          "include_dirs": [
            "<!(node -e \"require('nan')\")"
          ]
        }]
      ]
    }
  ]
}