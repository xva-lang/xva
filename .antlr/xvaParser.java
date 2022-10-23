// Generated from /Users/dylan/Projects/xva/xva.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class xvaParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, LET=3, MUTABLE=4, NULL=5, DEFAULT=6, TRUE=7, FALSE=8, 
		DEF=9, VOID=10, END=11, IF=12, ELSE=13, ELSE_IF=14, LOOP=15, BREAK=16, 
		WHILE=17, ASSIGNMENT_OPERATOR=18, LOWER_THAN_OPERATOR=19, LOWER_THAN_EQUAL_OPERATOR=20, 
		GREATER_THAN_OPERATOR=21, GREATER_THAN_EQUAL_OPERATOR=22, EQUALITY_OPERATOR=23, 
		IS_OPERATOR=24, INTEGER_CONSTANT_DECIMAL=25, INTEGER_CONSTANT_OCTAL=26, 
		INTEGER_CONSTANT_HEXADECIMAL=27, INTEGER_CONSTANT_BINARY=28, FLOAT_CONSTANT=29, 
		DOUBLE_CONSTANT=30, PRECISE_CONSTANT=31, CHAR_CONSTANT=32, STRING_CONSTANT=33, 
		IDENTIFIER=34, INTEGER_TYPE=35, FLOAT_TYPE=36, STRING_TYPE=37, BOOLEAN_TYPE=38, 
		SEMICOLON=39, COLON=40, FAT_ARROW=41, SINGLE_QUOTE=42, DOUBLE_QUOTE=43, 
		EMOTICONS=44, WS=45;
	public static final int
		RULE_module = 0, RULE_builtInType = 1, RULE_typeAnnotation = 2, RULE_declaration = 3, 
		RULE_assignment = 4, RULE_statement = 5, RULE_functionParameter = 6, RULE_returnType = 7, 
		RULE_parameterList = 8, RULE_simpleFunction = 9, RULE_complexFunction = 10, 
		RULE_lambdaExpr = 11, RULE_anonymousFunction = 12, RULE_integerConstant = 13, 
		RULE_floatConstant = 14, RULE_stringConstant = 15, RULE_charConstant = 16, 
		RULE_booleanConstant = 17, RULE_expression = 18, RULE_parenthesisedExpr = 19, 
		RULE_functionCall = 20, RULE_controlBlock = 21, RULE_ifBlock = 22, RULE_loopBlock = 23, 
		RULE_whileBlock = 24;
	private static String[] makeRuleNames() {
		return new String[] {
			"module", "builtInType", "typeAnnotation", "declaration", "assignment", 
			"statement", "functionParameter", "returnType", "parameterList", "simpleFunction", 
			"complexFunction", "lambdaExpr", "anonymousFunction", "integerConstant", 
			"floatConstant", "stringConstant", "charConstant", "booleanConstant", 
			"expression", "parenthesisedExpr", "functionCall", "controlBlock", "ifBlock", 
			"loopBlock", "whileBlock"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'let'", "'mutable'", "'null'", "'default'", "'true'", 
			"'false'", "'def'", "'void'", "'end'", "'if'", "'else'", "'else if'", 
			"'loop'", "'break'", "'while'", "'='", "'<'", "'<='", "'>'", "'>='", 
			"'=='", "'is'", null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "'boolean'", "';'", "':'", "'=>'", "'''", "'\"'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "LET", "MUTABLE", "NULL", "DEFAULT", "TRUE", "FALSE", 
			"DEF", "VOID", "END", "IF", "ELSE", "ELSE_IF", "LOOP", "BREAK", "WHILE", 
			"ASSIGNMENT_OPERATOR", "LOWER_THAN_OPERATOR", "LOWER_THAN_EQUAL_OPERATOR", 
			"GREATER_THAN_OPERATOR", "GREATER_THAN_EQUAL_OPERATOR", "EQUALITY_OPERATOR", 
			"IS_OPERATOR", "INTEGER_CONSTANT_DECIMAL", "INTEGER_CONSTANT_OCTAL", 
			"INTEGER_CONSTANT_HEXADECIMAL", "INTEGER_CONSTANT_BINARY", "FLOAT_CONSTANT", 
			"DOUBLE_CONSTANT", "PRECISE_CONSTANT", "CHAR_CONSTANT", "STRING_CONSTANT", 
			"IDENTIFIER", "INTEGER_TYPE", "FLOAT_TYPE", "STRING_TYPE", "BOOLEAN_TYPE", 
			"SEMICOLON", "COLON", "FAT_ARROW", "SINGLE_QUOTE", "DOUBLE_QUOTE", "EMOTICONS", 
			"WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "xva.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public xvaParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ModuleContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(xvaParser.EOF, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<SimpleFunctionContext> simpleFunction() {
			return getRuleContexts(SimpleFunctionContext.class);
		}
		public SimpleFunctionContext simpleFunction(int i) {
			return getRuleContext(SimpleFunctionContext.class,i);
		}
		public List<ComplexFunctionContext> complexFunction() {
			return getRuleContexts(ComplexFunctionContext.class);
		}
		public ComplexFunctionContext complexFunction(int i) {
			return getRuleContext(ComplexFunctionContext.class,i);
		}
		public List<ControlBlockContext> controlBlock() {
			return getRuleContexts(ControlBlockContext.class);
		}
		public ControlBlockContext controlBlock(int i) {
			return getRuleContext(ControlBlockContext.class,i);
		}
		public ModuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module; }
	}

	public final ModuleContext module() throws RecognitionException {
		ModuleContext _localctx = new ModuleContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_module);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(56);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << IF) | (1L << LOOP) | (1L << BREAK) | (1L << WHILE) | (1L << IDENTIFIER))) != 0)) {
				{
				setState(54);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(50);
					statement();
					}
					break;
				case 2:
					{
					setState(51);
					simpleFunction();
					}
					break;
				case 3:
					{
					setState(52);
					complexFunction();
					}
					break;
				case 4:
					{
					setState(53);
					controlBlock();
					}
					break;
				}
				}
				setState(58);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(59);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BuiltInTypeContext extends ParserRuleContext {
		public TerminalNode INTEGER_TYPE() { return getToken(xvaParser.INTEGER_TYPE, 0); }
		public TerminalNode FLOAT_TYPE() { return getToken(xvaParser.FLOAT_TYPE, 0); }
		public TerminalNode STRING_TYPE() { return getToken(xvaParser.STRING_TYPE, 0); }
		public TerminalNode BOOLEAN_TYPE() { return getToken(xvaParser.BOOLEAN_TYPE, 0); }
		public BuiltInTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_builtInType; }
	}

	public final BuiltInTypeContext builtInType() throws RecognitionException {
		BuiltInTypeContext _localctx = new BuiltInTypeContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_builtInType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTEGER_TYPE) | (1L << FLOAT_TYPE) | (1L << STRING_TYPE) | (1L << BOOLEAN_TYPE))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeAnnotationContext extends ParserRuleContext {
		public TerminalNode COLON() { return getToken(xvaParser.COLON, 0); }
		public BuiltInTypeContext builtInType() {
			return getRuleContext(BuiltInTypeContext.class,0);
		}
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public TerminalNode MUTABLE() { return getToken(xvaParser.MUTABLE, 0); }
		public TypeAnnotationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeAnnotation; }
	}

	public final TypeAnnotationContext typeAnnotation() throws RecognitionException {
		TypeAnnotationContext _localctx = new TypeAnnotationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_typeAnnotation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			match(COLON);
			setState(65);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==MUTABLE) {
				{
				setState(64);
				match(MUTABLE);
				}
			}

			setState(69);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INTEGER_TYPE:
			case FLOAT_TYPE:
			case STRING_TYPE:
			case BOOLEAN_TYPE:
				{
				setState(67);
				builtInType();
				}
				break;
			case IDENTIFIER:
				{
				setState(68);
				match(IDENTIFIER);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public TerminalNode LET() { return getToken(xvaParser.LET, 0); }
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public TerminalNode ASSIGNMENT_OPERATOR() { return getToken(xvaParser.ASSIGNMENT_OPERATOR, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TypeAnnotationContext typeAnnotation() {
			return getRuleContext(TypeAnnotationContext.class,0);
		}
		public SimpleFunctionContext simpleFunction() {
			return getRuleContext(SimpleFunctionContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_declaration);
		int _la;
		try {
			setState(79);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LET:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(71);
				match(LET);
				setState(72);
				match(IDENTIFIER);
				setState(74);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COLON) {
					{
					setState(73);
					typeAnnotation();
					}
				}

				setState(76);
				match(ASSIGNMENT_OPERATOR);
				setState(77);
				expression(0);
				}
				}
				break;
			case DEF:
				enterOuterAlt(_localctx, 2);
				{
				setState(78);
				simpleFunction();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public TerminalNode ASSIGNMENT_OPERATOR() { return getToken(xvaParser.ASSIGNMENT_OPERATOR, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_assignment);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(81);
			match(IDENTIFIER);
			setState(82);
			match(ASSIGNMENT_OPERATOR);
			setState(83);
			expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(xvaParser.SEMICOLON, 0); }
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public FunctionCallContext functionCall() {
			return getRuleContext(FunctionCallContext.class,0);
		}
		public TerminalNode BREAK() { return getToken(xvaParser.BREAK, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_statement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				setState(85);
				declaration();
				}
				break;
			case 2:
				{
				setState(86);
				assignment();
				}
				break;
			case 3:
				{
				setState(87);
				functionCall();
				}
				break;
			case 4:
				{
				setState(88);
				match(BREAK);
				}
				break;
			}
			setState(91);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionParameterContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public TypeAnnotationContext typeAnnotation() {
			return getRuleContext(TypeAnnotationContext.class,0);
		}
		public FunctionParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionParameter; }
	}

	public final FunctionParameterContext functionParameter() throws RecognitionException {
		FunctionParameterContext _localctx = new FunctionParameterContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_functionParameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			match(IDENTIFIER);
			setState(94);
			typeAnnotation();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReturnTypeContext extends ParserRuleContext {
		public TypeAnnotationContext typeAnnotation() {
			return getRuleContext(TypeAnnotationContext.class,0);
		}
		public TerminalNode COLON() { return getToken(xvaParser.COLON, 0); }
		public TerminalNode VOID() { return getToken(xvaParser.VOID, 0); }
		public ReturnTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnType; }
	}

	public final ReturnTypeContext returnType() throws RecognitionException {
		ReturnTypeContext _localctx = new ReturnTypeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_returnType);
		try {
			setState(99);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(96);
				typeAnnotation();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(97);
				match(COLON);
				setState(98);
				match(VOID);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterListContext extends ParserRuleContext {
		public List<FunctionParameterContext> functionParameter() {
			return getRuleContexts(FunctionParameterContext.class);
		}
		public FunctionParameterContext functionParameter(int i) {
			return getRuleContext(FunctionParameterContext.class,i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_parameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(101);
			match(T__0);
			setState(105);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==IDENTIFIER) {
				{
				{
				setState(102);
				functionParameter();
				}
				}
				setState(107);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(108);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleFunctionContext extends ParserRuleContext {
		public TerminalNode DEF() { return getToken(xvaParser.DEF, 0); }
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public ReturnTypeContext returnType() {
			return getRuleContext(ReturnTypeContext.class,0);
		}
		public TerminalNode FAT_ARROW() { return getToken(xvaParser.FAT_ARROW, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public SimpleFunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleFunction; }
	}

	public final SimpleFunctionContext simpleFunction() throws RecognitionException {
		SimpleFunctionContext _localctx = new SimpleFunctionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_simpleFunction);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			match(DEF);
			setState(111);
			match(IDENTIFIER);
			setState(112);
			parameterList();
			setState(113);
			returnType();
			setState(114);
			match(FAT_ARROW);
			setState(115);
			expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ComplexFunctionContext extends ParserRuleContext {
		public TerminalNode DEF() { return getToken(xvaParser.DEF, 0); }
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public ReturnTypeContext returnType() {
			return getRuleContext(ReturnTypeContext.class,0);
		}
		public TerminalNode END() { return getToken(xvaParser.END, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public ComplexFunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_complexFunction; }
	}

	public final ComplexFunctionContext complexFunction() throws RecognitionException {
		ComplexFunctionContext _localctx = new ComplexFunctionContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_complexFunction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(117);
			match(DEF);
			setState(118);
			match(IDENTIFIER);
			setState(119);
			parameterList();
			setState(120);
			returnType();
			setState(124);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(121);
				statement();
				}
				}
				setState(126);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(127);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LambdaExprContext extends ParserRuleContext {
		public TerminalNode DEF() { return getToken(xvaParser.DEF, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode FAT_ARROW() { return getToken(xvaParser.FAT_ARROW, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ReturnTypeContext returnType() {
			return getRuleContext(ReturnTypeContext.class,0);
		}
		public LambdaExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lambdaExpr; }
	}

	public final LambdaExprContext lambdaExpr() throws RecognitionException {
		LambdaExprContext _localctx = new LambdaExprContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_lambdaExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			match(DEF);
			setState(130);
			parameterList();
			setState(132);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(131);
				returnType();
				}
			}

			setState(134);
			match(FAT_ARROW);
			setState(135);
			expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AnonymousFunctionContext extends ParserRuleContext {
		public TerminalNode DEF() { return getToken(xvaParser.DEF, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode END() { return getToken(xvaParser.END, 0); }
		public ReturnTypeContext returnType() {
			return getRuleContext(ReturnTypeContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public AnonymousFunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_anonymousFunction; }
	}

	public final AnonymousFunctionContext anonymousFunction() throws RecognitionException {
		AnonymousFunctionContext _localctx = new AnonymousFunctionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_anonymousFunction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(137);
			match(DEF);
			setState(138);
			parameterList();
			setState(140);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(139);
				returnType();
				}
			}

			setState(145);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(142);
				statement();
				}
				}
				setState(147);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(148);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntegerConstantContext extends ParserRuleContext {
		public TerminalNode INTEGER_CONSTANT_DECIMAL() { return getToken(xvaParser.INTEGER_CONSTANT_DECIMAL, 0); }
		public TerminalNode INTEGER_CONSTANT_OCTAL() { return getToken(xvaParser.INTEGER_CONSTANT_OCTAL, 0); }
		public TerminalNode INTEGER_CONSTANT_HEXADECIMAL() { return getToken(xvaParser.INTEGER_CONSTANT_HEXADECIMAL, 0); }
		public TerminalNode INTEGER_CONSTANT_BINARY() { return getToken(xvaParser.INTEGER_CONSTANT_BINARY, 0); }
		public IntegerConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integerConstant; }
	}

	public final IntegerConstantContext integerConstant() throws RecognitionException {
		IntegerConstantContext _localctx = new IntegerConstantContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_integerConstant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(150);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTEGER_CONSTANT_DECIMAL) | (1L << INTEGER_CONSTANT_OCTAL) | (1L << INTEGER_CONSTANT_HEXADECIMAL) | (1L << INTEGER_CONSTANT_BINARY))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FloatConstantContext extends ParserRuleContext {
		public TerminalNode FLOAT_CONSTANT() { return getToken(xvaParser.FLOAT_CONSTANT, 0); }
		public TerminalNode DOUBLE_CONSTANT() { return getToken(xvaParser.DOUBLE_CONSTANT, 0); }
		public TerminalNode PRECISE_CONSTANT() { return getToken(xvaParser.PRECISE_CONSTANT, 0); }
		public FloatConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_floatConstant; }
	}

	public final FloatConstantContext floatConstant() throws RecognitionException {
		FloatConstantContext _localctx = new FloatConstantContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_floatConstant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(152);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << FLOAT_CONSTANT) | (1L << DOUBLE_CONSTANT) | (1L << PRECISE_CONSTANT))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringConstantContext extends ParserRuleContext {
		public TerminalNode STRING_CONSTANT() { return getToken(xvaParser.STRING_CONSTANT, 0); }
		public StringConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringConstant; }
	}

	public final StringConstantContext stringConstant() throws RecognitionException {
		StringConstantContext _localctx = new StringConstantContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_stringConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
			match(STRING_CONSTANT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CharConstantContext extends ParserRuleContext {
		public TerminalNode CHAR_CONSTANT() { return getToken(xvaParser.CHAR_CONSTANT, 0); }
		public CharConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_charConstant; }
	}

	public final CharConstantContext charConstant() throws RecognitionException {
		CharConstantContext _localctx = new CharConstantContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_charConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(156);
			match(CHAR_CONSTANT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BooleanConstantContext extends ParserRuleContext {
		public TerminalNode TRUE() { return getToken(xvaParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(xvaParser.FALSE, 0); }
		public BooleanConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanConstant; }
	}

	public final BooleanConstantContext booleanConstant() throws RecognitionException {
		BooleanConstantContext _localctx = new BooleanConstantContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_booleanConstant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			_la = _input.LA(1);
			if ( !(_la==TRUE || _la==FALSE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class AnonymousFunctionExpressionContext extends ExpressionContext {
		public AnonymousFunctionContext anonymousFunction() {
			return getRuleContext(AnonymousFunctionContext.class,0);
		}
		public AnonymousFunctionExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class TernaryExpressionContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode IF() { return getToken(xvaParser.IF, 0); }
		public TerminalNode ELSE() { return getToken(xvaParser.ELSE, 0); }
		public TernaryExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class BooleanExpressionContext extends ExpressionContext {
		public BooleanConstantContext booleanConstant() {
			return getRuleContext(BooleanConstantContext.class,0);
		}
		public BooleanExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ParenthesisedExpressionContext extends ExpressionContext {
		public ParenthesisedExprContext parenthesisedExpr() {
			return getRuleContext(ParenthesisedExprContext.class,0);
		}
		public ParenthesisedExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class CharExpressionContext extends ExpressionContext {
		public CharConstantContext charConstant() {
			return getRuleContext(CharConstantContext.class,0);
		}
		public CharExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class StringExpressionContext extends ExpressionContext {
		public StringConstantContext stringConstant() {
			return getRuleContext(StringConstantContext.class,0);
		}
		public StringExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class IntegerExpresssionContext extends ExpressionContext {
		public IntegerConstantContext integerConstant() {
			return getRuleContext(IntegerConstantContext.class,0);
		}
		public IntegerExpresssionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class FloatExpressionContext extends ExpressionContext {
		public FloatConstantContext floatConstant() {
			return getRuleContext(FloatConstantContext.class,0);
		}
		public FloatExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class LambdaExpressionContext extends ExpressionContext {
		public LambdaExprContext lambdaExpr() {
			return getRuleContext(LambdaExprContext.class,0);
		}
		public LambdaExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class IdentifierExpressionContext extends ExpressionContext {
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public IdentifierExpressionContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				_localctx = new IntegerExpresssionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(161);
				integerConstant();
				}
				break;
			case 2:
				{
				_localctx = new BooleanExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(162);
				booleanConstant();
				}
				break;
			case 3:
				{
				_localctx = new FloatExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(163);
				floatConstant();
				}
				break;
			case 4:
				{
				_localctx = new CharExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(164);
				charConstant();
				}
				break;
			case 5:
				{
				_localctx = new StringExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(165);
				stringConstant();
				}
				break;
			case 6:
				{
				_localctx = new AnonymousFunctionExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(166);
				anonymousFunction();
				}
				break;
			case 7:
				{
				_localctx = new LambdaExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(167);
				lambdaExpr();
				}
				break;
			case 8:
				{
				_localctx = new ParenthesisedExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(168);
				parenthesisedExpr();
				}
				break;
			case 9:
				{
				_localctx = new IdentifierExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(169);
				match(IDENTIFIER);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(180);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TernaryExpressionContext(new ExpressionContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_expression);
					setState(172);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(173);
					match(IF);
					setState(174);
					expression(0);
					setState(175);
					match(ELSE);
					setState(176);
					expression(3);
					}
					} 
				}
				setState(182);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ParenthesisedExprContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ParenthesisedExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parenthesisedExpr; }
	}

	public final ParenthesisedExprContext parenthesisedExpr() throws RecognitionException {
		ParenthesisedExprContext _localctx = new ParenthesisedExprContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_parenthesisedExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(183);
			match(T__0);
			setState(184);
			expression(0);
			setState(185);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionCallContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(xvaParser.IDENTIFIER, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public FunctionCallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionCall; }
	}

	public final FunctionCallContext functionCall() throws RecognitionException {
		FunctionCallContext _localctx = new FunctionCallContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_functionCall);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(187);
			match(IDENTIFIER);
			setState(188);
			match(T__0);
			setState(192);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << TRUE) | (1L << FALSE) | (1L << DEF) | (1L << INTEGER_CONSTANT_DECIMAL) | (1L << INTEGER_CONSTANT_OCTAL) | (1L << INTEGER_CONSTANT_HEXADECIMAL) | (1L << INTEGER_CONSTANT_BINARY) | (1L << FLOAT_CONSTANT) | (1L << DOUBLE_CONSTANT) | (1L << PRECISE_CONSTANT) | (1L << CHAR_CONSTANT) | (1L << STRING_CONSTANT) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(189);
				expression(0);
				}
				}
				setState(194);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(195);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ControlBlockContext extends ParserRuleContext {
		public IfBlockContext ifBlock() {
			return getRuleContext(IfBlockContext.class,0);
		}
		public LoopBlockContext loopBlock() {
			return getRuleContext(LoopBlockContext.class,0);
		}
		public WhileBlockContext whileBlock() {
			return getRuleContext(WhileBlockContext.class,0);
		}
		public ControlBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_controlBlock; }
	}

	public final ControlBlockContext controlBlock() throws RecognitionException {
		ControlBlockContext _localctx = new ControlBlockContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_controlBlock);
		try {
			setState(200);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(197);
				ifBlock();
				}
				break;
			case LOOP:
				enterOuterAlt(_localctx, 2);
				{
				setState(198);
				loopBlock();
				}
				break;
			case WHILE:
				enterOuterAlt(_localctx, 3);
				{
				setState(199);
				whileBlock();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfBlockContext extends ParserRuleContext {
		public TerminalNode END() { return getToken(xvaParser.END, 0); }
		public TerminalNode IF() { return getToken(xvaParser.IF, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(xvaParser.ELSE, 0); }
		public List<TerminalNode> ELSE_IF() { return getTokens(xvaParser.ELSE_IF); }
		public TerminalNode ELSE_IF(int i) {
			return getToken(xvaParser.ELSE_IF, i);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public IfBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifBlock; }
	}

	public final IfBlockContext ifBlock() throws RecognitionException {
		IfBlockContext _localctx = new IfBlockContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_ifBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(202);
			match(IF);
			setState(203);
			expression(0);
			setState(207);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(204);
				statement();
				}
				}
				setState(209);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			setState(220);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ELSE_IF) {
				{
				{
				setState(210);
				match(ELSE_IF);
				setState(211);
				expression(0);
				setState(215);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
					{
					{
					setState(212);
					statement();
					}
					}
					setState(217);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				setState(222);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			{
			setState(223);
			match(ELSE);
			setState(227);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(224);
				statement();
				}
				}
				setState(229);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			setState(230);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LoopBlockContext extends ParserRuleContext {
		public TerminalNode LOOP() { return getToken(xvaParser.LOOP, 0); }
		public TerminalNode END() { return getToken(xvaParser.END, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public LoopBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loopBlock; }
	}

	public final LoopBlockContext loopBlock() throws RecognitionException {
		LoopBlockContext _localctx = new LoopBlockContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_loopBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(232);
			match(LOOP);
			setState(236);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(233);
				statement();
				}
				}
				setState(238);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(239);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileBlockContext extends ParserRuleContext {
		public TerminalNode WHILE() { return getToken(xvaParser.WHILE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode END() { return getToken(xvaParser.END, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public WhileBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileBlock; }
	}

	public final WhileBlockContext whileBlock() throws RecognitionException {
		WhileBlockContext _localctx = new WhileBlockContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_whileBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(241);
			match(WHILE);
			setState(242);
			expression(0);
			setState(246);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LET) | (1L << DEF) | (1L << BREAK) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(243);
				statement();
				}
				}
				setState(248);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(249);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 18:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3/\u00fe\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\3\2\3\2\3\2\3\2\7\29\n\2\f\2\16\2<\13\2\3\2\3\2\3\3\3\3\3\4"+
		"\3\4\5\4D\n\4\3\4\3\4\5\4H\n\4\3\5\3\5\3\5\5\5M\n\5\3\5\3\5\3\5\5\5R\n"+
		"\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\5\7\\\n\7\3\7\3\7\3\b\3\b\3\b\3\t\3"+
		"\t\3\t\5\tf\n\t\3\n\3\n\7\nj\n\n\f\n\16\nm\13\n\3\n\3\n\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\7\f}\n\f\f\f\16\f\u0080\13\f"+
		"\3\f\3\f\3\r\3\r\3\r\5\r\u0087\n\r\3\r\3\r\3\r\3\16\3\16\3\16\5\16\u008f"+
		"\n\16\3\16\7\16\u0092\n\16\f\16\16\16\u0095\13\16\3\16\3\16\3\17\3\17"+
		"\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\24"+
		"\3\24\3\24\3\24\3\24\5\24\u00ad\n\24\3\24\3\24\3\24\3\24\3\24\3\24\7\24"+
		"\u00b5\n\24\f\24\16\24\u00b8\13\24\3\25\3\25\3\25\3\25\3\26\3\26\3\26"+
		"\7\26\u00c1\n\26\f\26\16\26\u00c4\13\26\3\26\3\26\3\27\3\27\3\27\5\27"+
		"\u00cb\n\27\3\30\3\30\3\30\7\30\u00d0\n\30\f\30\16\30\u00d3\13\30\3\30"+
		"\3\30\3\30\7\30\u00d8\n\30\f\30\16\30\u00db\13\30\7\30\u00dd\n\30\f\30"+
		"\16\30\u00e0\13\30\3\30\3\30\7\30\u00e4\n\30\f\30\16\30\u00e7\13\30\3"+
		"\30\3\30\3\31\3\31\7\31\u00ed\n\31\f\31\16\31\u00f0\13\31\3\31\3\31\3"+
		"\32\3\32\3\32\7\32\u00f7\n\32\f\32\16\32\u00fa\13\32\3\32\3\32\3\32\2"+
		"\3&\33\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\2\6\3\2%"+
		"(\3\2\33\36\3\2\37!\3\2\t\n\2\u0107\2:\3\2\2\2\4?\3\2\2\2\6A\3\2\2\2\b"+
		"Q\3\2\2\2\nS\3\2\2\2\f[\3\2\2\2\16_\3\2\2\2\20e\3\2\2\2\22g\3\2\2\2\24"+
		"p\3\2\2\2\26w\3\2\2\2\30\u0083\3\2\2\2\32\u008b\3\2\2\2\34\u0098\3\2\2"+
		"\2\36\u009a\3\2\2\2 \u009c\3\2\2\2\"\u009e\3\2\2\2$\u00a0\3\2\2\2&\u00ac"+
		"\3\2\2\2(\u00b9\3\2\2\2*\u00bd\3\2\2\2,\u00ca\3\2\2\2.\u00cc\3\2\2\2\60"+
		"\u00ea\3\2\2\2\62\u00f3\3\2\2\2\649\5\f\7\2\659\5\24\13\2\669\5\26\f\2"+
		"\679\5,\27\28\64\3\2\2\28\65\3\2\2\28\66\3\2\2\28\67\3\2\2\29<\3\2\2\2"+
		":8\3\2\2\2:;\3\2\2\2;=\3\2\2\2<:\3\2\2\2=>\7\2\2\3>\3\3\2\2\2?@\t\2\2"+
		"\2@\5\3\2\2\2AC\7*\2\2BD\7\6\2\2CB\3\2\2\2CD\3\2\2\2DG\3\2\2\2EH\5\4\3"+
		"\2FH\7$\2\2GE\3\2\2\2GF\3\2\2\2H\7\3\2\2\2IJ\7\5\2\2JL\7$\2\2KM\5\6\4"+
		"\2LK\3\2\2\2LM\3\2\2\2MN\3\2\2\2NO\7\24\2\2OR\5&\24\2PR\5\24\13\2QI\3"+
		"\2\2\2QP\3\2\2\2R\t\3\2\2\2ST\7$\2\2TU\7\24\2\2UV\5&\24\2V\13\3\2\2\2"+
		"W\\\5\b\5\2X\\\5\n\6\2Y\\\5*\26\2Z\\\7\22\2\2[W\3\2\2\2[X\3\2\2\2[Y\3"+
		"\2\2\2[Z\3\2\2\2\\]\3\2\2\2]^\7)\2\2^\r\3\2\2\2_`\7$\2\2`a\5\6\4\2a\17"+
		"\3\2\2\2bf\5\6\4\2cd\7*\2\2df\7\f\2\2eb\3\2\2\2ec\3\2\2\2f\21\3\2\2\2"+
		"gk\7\3\2\2hj\5\16\b\2ih\3\2\2\2jm\3\2\2\2ki\3\2\2\2kl\3\2\2\2ln\3\2\2"+
		"\2mk\3\2\2\2no\7\4\2\2o\23\3\2\2\2pq\7\13\2\2qr\7$\2\2rs\5\22\n\2st\5"+
		"\20\t\2tu\7+\2\2uv\5&\24\2v\25\3\2\2\2wx\7\13\2\2xy\7$\2\2yz\5\22\n\2"+
		"z~\5\20\t\2{}\5\f\7\2|{\3\2\2\2}\u0080\3\2\2\2~|\3\2\2\2~\177\3\2\2\2"+
		"\177\u0081\3\2\2\2\u0080~\3\2\2\2\u0081\u0082\7\r\2\2\u0082\27\3\2\2\2"+
		"\u0083\u0084\7\13\2\2\u0084\u0086\5\22\n\2\u0085\u0087\5\20\t\2\u0086"+
		"\u0085\3\2\2\2\u0086\u0087\3\2\2\2\u0087\u0088\3\2\2\2\u0088\u0089\7+"+
		"\2\2\u0089\u008a\5&\24\2\u008a\31\3\2\2\2\u008b\u008c\7\13\2\2\u008c\u008e"+
		"\5\22\n\2\u008d\u008f\5\20\t\2\u008e\u008d\3\2\2\2\u008e\u008f\3\2\2\2"+
		"\u008f\u0093\3\2\2\2\u0090\u0092\5\f\7\2\u0091\u0090\3\2\2\2\u0092\u0095"+
		"\3\2\2\2\u0093\u0091\3\2\2\2\u0093\u0094\3\2\2\2\u0094\u0096\3\2\2\2\u0095"+
		"\u0093\3\2\2\2\u0096\u0097\7\r\2\2\u0097\33\3\2\2\2\u0098\u0099\t\3\2"+
		"\2\u0099\35\3\2\2\2\u009a\u009b\t\4\2\2\u009b\37\3\2\2\2\u009c\u009d\7"+
		"#\2\2\u009d!\3\2\2\2\u009e\u009f\7\"\2\2\u009f#\3\2\2\2\u00a0\u00a1\t"+
		"\5\2\2\u00a1%\3\2\2\2\u00a2\u00a3\b\24\1\2\u00a3\u00ad\5\34\17\2\u00a4"+
		"\u00ad\5$\23\2\u00a5\u00ad\5\36\20\2\u00a6\u00ad\5\"\22\2\u00a7\u00ad"+
		"\5 \21\2\u00a8\u00ad\5\32\16\2\u00a9\u00ad\5\30\r\2\u00aa\u00ad\5(\25"+
		"\2\u00ab\u00ad\7$\2\2\u00ac\u00a2\3\2\2\2\u00ac\u00a4\3\2\2\2\u00ac\u00a5"+
		"\3\2\2\2\u00ac\u00a6\3\2\2\2\u00ac\u00a7\3\2\2\2\u00ac\u00a8\3\2\2\2\u00ac"+
		"\u00a9\3\2\2\2\u00ac\u00aa\3\2\2\2\u00ac\u00ab\3\2\2\2\u00ad\u00b6\3\2"+
		"\2\2\u00ae\u00af\f\4\2\2\u00af\u00b0\7\16\2\2\u00b0\u00b1\5&\24\2\u00b1"+
		"\u00b2\7\17\2\2\u00b2\u00b3\5&\24\5\u00b3\u00b5\3\2\2\2\u00b4\u00ae\3"+
		"\2\2\2\u00b5\u00b8\3\2\2\2\u00b6\u00b4\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7"+
		"\'\3\2\2\2\u00b8\u00b6\3\2\2\2\u00b9\u00ba\7\3\2\2\u00ba\u00bb\5&\24\2"+
		"\u00bb\u00bc\7\4\2\2\u00bc)\3\2\2\2\u00bd\u00be\7$\2\2\u00be\u00c2\7\3"+
		"\2\2\u00bf\u00c1\5&\24\2\u00c0\u00bf\3\2\2\2\u00c1\u00c4\3\2\2\2\u00c2"+
		"\u00c0\3\2\2\2\u00c2\u00c3\3\2\2\2\u00c3\u00c5\3\2\2\2\u00c4\u00c2\3\2"+
		"\2\2\u00c5\u00c6\7\4\2\2\u00c6+\3\2\2\2\u00c7\u00cb\5.\30\2\u00c8\u00cb"+
		"\5\60\31\2\u00c9\u00cb\5\62\32\2\u00ca\u00c7\3\2\2\2\u00ca\u00c8\3\2\2"+
		"\2\u00ca\u00c9\3\2\2\2\u00cb-\3\2\2\2\u00cc\u00cd\7\16\2\2\u00cd\u00d1"+
		"\5&\24\2\u00ce\u00d0\5\f\7\2\u00cf\u00ce\3\2\2\2\u00d0\u00d3\3\2\2\2\u00d1"+
		"\u00cf\3\2\2\2\u00d1\u00d2\3\2\2\2\u00d2\u00de\3\2\2\2\u00d3\u00d1\3\2"+
		"\2\2\u00d4\u00d5\7\20\2\2\u00d5\u00d9\5&\24\2\u00d6\u00d8\5\f\7\2\u00d7"+
		"\u00d6\3\2\2\2\u00d8\u00db\3\2\2\2\u00d9\u00d7\3\2\2\2\u00d9\u00da\3\2"+
		"\2\2\u00da\u00dd\3\2\2\2\u00db\u00d9\3\2\2\2\u00dc\u00d4\3\2\2\2\u00dd"+
		"\u00e0\3\2\2\2\u00de\u00dc\3\2\2\2\u00de\u00df\3\2\2\2\u00df\u00e1\3\2"+
		"\2\2\u00e0\u00de\3\2\2\2\u00e1\u00e5\7\17\2\2\u00e2\u00e4\5\f\7\2\u00e3"+
		"\u00e2\3\2\2\2\u00e4\u00e7\3\2\2\2\u00e5\u00e3\3\2\2\2\u00e5\u00e6\3\2"+
		"\2\2\u00e6\u00e8\3\2\2\2\u00e7\u00e5\3\2\2\2\u00e8\u00e9\7\r\2\2\u00e9"+
		"/\3\2\2\2\u00ea\u00ee\7\21\2\2\u00eb\u00ed\5\f\7\2\u00ec\u00eb\3\2\2\2"+
		"\u00ed\u00f0\3\2\2\2\u00ee\u00ec\3\2\2\2\u00ee\u00ef\3\2\2\2\u00ef\u00f1"+
		"\3\2\2\2\u00f0\u00ee\3\2\2\2\u00f1\u00f2\7\r\2\2\u00f2\61\3\2\2\2\u00f3"+
		"\u00f4\7\23\2\2\u00f4\u00f8\5&\24\2\u00f5\u00f7\5\f\7\2\u00f6\u00f5\3"+
		"\2\2\2\u00f7\u00fa\3\2\2\2\u00f8\u00f6\3\2\2\2\u00f8\u00f9\3\2\2\2\u00f9"+
		"\u00fb\3\2\2\2\u00fa\u00f8\3\2\2\2\u00fb\u00fc\7\r\2\2\u00fc\63\3\2\2"+
		"\2\318:CGLQ[ek~\u0086\u008e\u0093\u00ac\u00b6\u00c2\u00ca\u00d1\u00d9"+
		"\u00de\u00e5\u00ee\u00f8";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}