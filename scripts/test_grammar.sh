export CLASSPATH=".:/usr/local/lib/antlr/antlr4-4.8-2-SNAPSHOT-complete.jar:$CLASSPATH"
alias grun='java org.antlr.v4.runtime.misc.TestRig'
alias antlr4='java org.antlr.v4.Tool'
cd tests
cp ../src/parser/xva.g4 ./xva.g4
antlr4 xva.g4
javac xva*.java
grun xva module test.xva -tree -gui
rm xva.g4
