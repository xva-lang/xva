Set-Location treesitter
tree-sitter build-wasm
Move-Item -Path tree-sitter-xva.wasm -Destination bindings\node\tree-sitter-xva.wasm -Force
