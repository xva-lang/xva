export CLASSPATH=".:/usr/local/lib/antlr/antlr4-4.8-2-SNAPSHOT-complete.jar:$CLASSPATH"
alias grun='java org.antlr.v4.runtime.misc.TestRig'
alias antlr4='java org.antlr.v4.Tool'
antlr4 -Dlanguage=Rust src/parser/Xva.g4