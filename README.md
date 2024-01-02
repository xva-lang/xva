<p align="center">
  <img width="200" height="200" src="https://avatars.githubusercontent.com/u/116477927?s=200&v=4">
</p>

<h1 align="center">xva</h1>

<div align="center">
  <i>ˈk(w)iːvə, QUEE-va, like the Irish name Caoimhe</i>
</div>

<div align="center">
  <h2>The Xva programming language</h2>
</div>

Xva is an interpreted, statically typed programming language, designed to be small, fast, and allow for rapid prototyping. Its syntax is beginner friendly, but also exposes many common and powerful features found in other languages.

Xva started out with us wanting something that satisfied some "gripes" with other languages we have used in a professional context. Some languages didn't have what we wanted, some had unwieldy syntax, and some were just plain weird. So we decided we'd build our own, to make something expressive and easy to use, without compromising its power and productivity.

Xva is still extremely experimental. The team is always open to new ideas and contributions, so if you feel like adding something, please go ahead and make a pull request!

<br/>

# Setting up for development

Xva is written in Rust. We are using the latest stable Rust version, which you can get by downloading [Rustup](https://www.rust-lang.org/tools/install), the Rust toolchain installer.

Rust is all you need to get started! However, the `treesitter` crate has a dependency on the famous [Tree Sitter](https://tree-sitter.github.io/tree-sitter) parsing library. Building the crate as-is does not require any extra dependencies,
however, changing the Tree Sitter grammar and testing it requires a few development dependencies, so if you are
interested in working on that crate, please read on.

## Tree Sitter

Tree Sitter requires a few prerequesites to be able to get going with developing and testing the grammar.

- tree-sitter-cli
- Node
- A C and C++ compiler

### tree-sitter-cli

This binary is what will be generating the Rust bindings for the Tree Sitter library. This is a Cargo utility, so you can install it using the following command:

```bash
$ cargo install tree-sitter-cli
```

You may have to restart your shell after installing it.

### Node

The tree-sitter-cli requires Node to generate parsers. Head to the [Node website](https://nodejs.org/en/download) and find instructions relevant to your operating system.

### C and C++ compiler

The tree-sitter-cli requires a C and C++ compiler for building, testing and running parsers, as Tree Sitter itself is a C library. Because there are a multitude of different C/C++ compilers for a multitude of different operating systems,
instructions to install one is outside the scope of this document and it is assumed you have now installed one.
