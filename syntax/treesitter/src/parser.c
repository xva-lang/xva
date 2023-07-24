#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 62
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 65
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 3

enum {
  sym_identifier = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_COLON = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COMMA = 6,
  anon_sym_RPAREN = 7,
  anon_sym_def = 8,
  sym__fat_arrow = 9,
  sym_mutable_modifier = 10,
  sym__equals_symbol = 11,
  sym__let_keyword = 12,
  anon_sym_byte = 13,
  anon_sym_ushort = 14,
  anon_sym_uint = 15,
  anon_sym_ulong = 16,
  anon_sym_sbyte = 17,
  anon_sym_short = 18,
  anon_sym_int = 19,
  anon_sym_long = 20,
  anon_sym_float = 21,
  anon_sym_double = 22,
  anon_sym_boolean = 23,
  anon_sym_char = 24,
  anon_sym_DASH = 25,
  anon_sym_not = 26,
  anon_sym_PLUS = 27,
  anon_sym_STAR = 28,
  anon_sym_SLASH = 29,
  anon_sym_PERCENT = 30,
  anon_sym_STAR_STAR = 31,
  sym_hex_literal = 32,
  sym_octal_literal = 33,
  sym_binary_literal = 34,
  sym_decimal_literal = 35,
  sym_boolean_literal = 36,
  anon_sym_DQUOTE = 37,
  anon_sym_SQUOTE = 38,
  sym_character_literal_unescaped = 39,
  sym_escape_sequence = 40,
  sym_source_file = 41,
  sym__statement = 42,
  sym__declaration_statement = 43,
  sym_let_declaration = 44,
  sym_assignment = 45,
  sym_type_annotation = 46,
  sym_block = 47,
  sym_parameter = 48,
  sym_parameters = 49,
  sym_function = 50,
  sym_arrow_function_body = 51,
  sym_type = 52,
  sym__colon_symbol = 53,
  sym_built_in_type = 54,
  sym__expression = 55,
  sym_unary_expression = 56,
  sym_binary_expression = 57,
  sym_string_literal = 58,
  sym_character_literal = 59,
  sym_literal = 60,
  aux_sym_source_file_repeat1 = 61,
  aux_sym_block_repeat1 = 62,
  aux_sym_parameters_repeat1 = 63,
  aux_sym_string_literal_repeat1 = 64,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COLON] = ":",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_def] = "def",
  [sym__fat_arrow] = "_fat_arrow",
  [sym_mutable_modifier] = "mutable_modifier",
  [sym__equals_symbol] = "_equals_symbol",
  [sym__let_keyword] = "_let_keyword",
  [anon_sym_byte] = "byte",
  [anon_sym_ushort] = "ushort",
  [anon_sym_uint] = "uint",
  [anon_sym_ulong] = "ulong",
  [anon_sym_sbyte] = "sbyte",
  [anon_sym_short] = "short",
  [anon_sym_int] = "int",
  [anon_sym_long] = "long",
  [anon_sym_float] = "float",
  [anon_sym_double] = "double",
  [anon_sym_boolean] = "boolean",
  [anon_sym_char] = "char",
  [anon_sym_DASH] = "-",
  [anon_sym_not] = "not",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_STAR_STAR] = "**",
  [sym_hex_literal] = "hex_literal",
  [sym_octal_literal] = "octal_literal",
  [sym_binary_literal] = "binary_literal",
  [sym_decimal_literal] = "decimal_literal",
  [sym_boolean_literal] = "boolean_literal",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_character_literal_unescaped] = "character_literal_unescaped",
  [sym_escape_sequence] = "escape_sequence",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__declaration_statement] = "_declaration_statement",
  [sym_let_declaration] = "let_declaration",
  [sym_assignment] = "assignment",
  [sym_type_annotation] = "type_annotation",
  [sym_block] = "block",
  [sym_parameter] = "parameter",
  [sym_parameters] = "parameters",
  [sym_function] = "function",
  [sym_arrow_function_body] = "arrow_function_body",
  [sym_type] = "type",
  [sym__colon_symbol] = "_colon_symbol",
  [sym_built_in_type] = "built_in_type",
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_string_literal] = "string_literal",
  [sym_character_literal] = "character_literal",
  [sym_literal] = "literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_def] = anon_sym_def,
  [sym__fat_arrow] = sym__fat_arrow,
  [sym_mutable_modifier] = sym_mutable_modifier,
  [sym__equals_symbol] = sym__equals_symbol,
  [sym__let_keyword] = sym__let_keyword,
  [anon_sym_byte] = anon_sym_byte,
  [anon_sym_ushort] = anon_sym_ushort,
  [anon_sym_uint] = anon_sym_uint,
  [anon_sym_ulong] = anon_sym_ulong,
  [anon_sym_sbyte] = anon_sym_sbyte,
  [anon_sym_short] = anon_sym_short,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_long] = anon_sym_long,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_double] = anon_sym_double,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [sym_hex_literal] = sym_hex_literal,
  [sym_octal_literal] = sym_octal_literal,
  [sym_binary_literal] = sym_binary_literal,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_character_literal_unescaped] = sym_character_literal_unescaped,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__declaration_statement] = sym__declaration_statement,
  [sym_let_declaration] = sym_let_declaration,
  [sym_assignment] = sym_assignment,
  [sym_type_annotation] = sym_type_annotation,
  [sym_block] = sym_block,
  [sym_parameter] = sym_parameter,
  [sym_parameters] = sym_parameters,
  [sym_function] = sym_function,
  [sym_arrow_function_body] = sym_arrow_function_body,
  [sym_type] = sym_type,
  [sym__colon_symbol] = sym__colon_symbol,
  [sym_built_in_type] = sym_built_in_type,
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_string_literal] = sym_string_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_literal] = sym_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [sym__fat_arrow] = {
    .visible = false,
    .named = true,
  },
  [sym_mutable_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__equals_symbol] = {
    .visible = false,
    .named = true,
  },
  [sym__let_keyword] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_byte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ushort] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ulong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sbyte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_short] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_long] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_double] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [sym_hex_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_character_literal_unescaped] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__declaration_statement] = {
    .visible = false,
    .named = true,
  },
  [sym_let_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_type_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_function] = {
    .visible = true,
    .named = true,
  },
  [sym_arrow_function_body] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__colon_symbol] = {
    .visible = false,
    .named = true,
  },
  [sym_built_in_type] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_character_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_name = 2,
  field_return_type = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
  [field_return_type] = "return_type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_body, 3},
    {field_name, 1},
  [2] =
    {field_body, 4},
    {field_name, 1},
    {field_return_type, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(25);
      if (lookahead == '"') ADVANCE(46);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '(') ADVANCE(29);
      if (lookahead == ')') ADVANCE(31);
      if (lookahead == '*') ADVANCE(37);
      if (lookahead == '+') ADVANCE(36);
      if (lookahead == ',') ADVANCE(30);
      if (lookahead == '-') ADVANCE(35);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == '0') ADVANCE(45);
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '=') ADVANCE(34);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '{') ADVANCE(26);
      if (lookahead == '}') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 1:
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '=') ADVANCE(3);
      if (lookahead == '{') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '=') ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '>') ADVANCE(32);
      END_STATE();
    case 4:
      if (lookahead == 'U') ADVANCE(24);
      if (lookahead == 'u') ADVANCE(20);
      if (lookahead == 'x') ADVANCE(16);
      if (lookahead != 0) ADVANCE(49);
      END_STATE();
    case 5:
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(48);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(11);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(43);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(42);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 10:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(43);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(8);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(42);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(14);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(18);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__fat_arrow);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__equals_symbol);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__equals_symbol);
      if (lookahead == '>') ADVANCE(32);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(40);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_hex_literal);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_octal_literal);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_binary_literal);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(10);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(12);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(15);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_character_literal_unescaped);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'c') ADVANCE(2);
      if (lookahead == 'd') ADVANCE(3);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 'l') ADVANCE(6);
      if (lookahead == 'm') ADVANCE(7);
      if (lookahead == 'n') ADVANCE(8);
      if (lookahead == 's') ADVANCE(9);
      if (lookahead == 't') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(12);
      if (lookahead == 'y') ADVANCE(13);
      END_STATE();
    case 2:
      if (lookahead == 'h') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(15);
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(17);
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 5:
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(20);
      if (lookahead == 'o') ADVANCE(21);
      END_STATE();
    case 7:
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(23);
      END_STATE();
    case 9:
      if (lookahead == 'b') ADVANCE(24);
      if (lookahead == 'h') ADVANCE(25);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(27);
      if (lookahead == 'l') ADVANCE(28);
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 12:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(32);
      END_STATE();
    case 15:
      if (lookahead == 'f') ADVANCE(33);
      END_STATE();
    case 16:
      if (lookahead == 'u') ADVANCE(34);
      END_STATE();
    case 17:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 18:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 21:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 24:
      if (lookahead == 'y') ADVANCE(42);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 26:
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 27:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 28:
      if (lookahead == 'o') ADVANCE(46);
      END_STATE();
    case 29:
      if (lookahead == 'h') ADVANCE(47);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(48);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 34:
      if (lookahead == 'b') ADVANCE(51);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(52);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__let_keyword);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(54);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 42:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 45:
      if (lookahead == 't') ADVANCE(59);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(61);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 51:
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_long);
      END_STATE();
    case 55:
      if (lookahead == 'b') ADVANCE(65);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(67);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_boolean_literal);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_uint);
      END_STATE();
    case 60:
      if (lookahead == 'g') ADVANCE(68);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(69);
      END_STATE();
    case 62:
      if (lookahead == 'a') ADVANCE(70);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_sbyte);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_short);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_ulong);
      END_STATE();
    case 69:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_double);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_ushort);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_mutable_modifier);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 5},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [sym__fat_arrow] = ACTIONS(1),
    [sym_mutable_modifier] = ACTIONS(1),
    [sym__equals_symbol] = ACTIONS(1),
    [sym__let_keyword] = ACTIONS(1),
    [anon_sym_byte] = ACTIONS(1),
    [anon_sym_ushort] = ACTIONS(1),
    [anon_sym_uint] = ACTIONS(1),
    [anon_sym_ulong] = ACTIONS(1),
    [anon_sym_sbyte] = ACTIONS(1),
    [anon_sym_short] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_long] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_double] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [sym_hex_literal] = ACTIONS(1),
    [sym_octal_literal] = ACTIONS(1),
    [sym_binary_literal] = ACTIONS(1),
    [sym_decimal_literal] = ACTIONS(1),
    [sym_boolean_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(57),
    [sym__statement] = STATE(2),
    [sym__declaration_statement] = STATE(2),
    [sym_let_declaration] = STATE(2),
    [sym_function] = STATE(2),
    [sym__expression] = STATE(17),
    [sym_unary_expression] = STATE(17),
    [sym_binary_expression] = STATE(17),
    [sym_string_literal] = STATE(8),
    [sym_character_literal] = STATE(8),
    [sym_literal] = STATE(17),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
    [anon_sym_def] = ACTIONS(7),
    [sym__let_keyword] = ACTIONS(9),
    [anon_sym_DASH] = ACTIONS(11),
    [anon_sym_not] = ACTIONS(13),
    [sym_hex_literal] = ACTIONS(15),
    [sym_octal_literal] = ACTIONS(15),
    [sym_binary_literal] = ACTIONS(15),
    [sym_decimal_literal] = ACTIONS(17),
    [sym_boolean_literal] = ACTIONS(17),
    [anon_sym_DQUOTE] = ACTIONS(19),
    [anon_sym_SQUOTE] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(5), 1,
      sym_identifier,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      sym__let_keyword,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(17), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(3), 5,
      sym__statement,
      sym__declaration_statement,
      sym_let_declaration,
      sym_function,
      aux_sym_source_file_repeat1,
  [51] = 13,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(30), 1,
      anon_sym_def,
    ACTIONS(33), 1,
      sym__let_keyword,
    ACTIONS(36), 1,
      anon_sym_DASH,
    ACTIONS(39), 1,
      anon_sym_not,
    ACTIONS(48), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_SQUOTE,
    ACTIONS(45), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(42), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(17), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(3), 5,
      sym__statement,
      sym__declaration_statement,
      sym_let_declaration,
      sym_function,
      aux_sym_source_file_repeat1,
  [102] = 13,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      sym__let_keyword,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      sym_identifier,
    ACTIONS(56), 1,
      anon_sym_RBRACE,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(6), 4,
      sym__declaration_statement,
      sym_let_declaration,
      sym_function,
      aux_sym_block_repeat1,
    STATE(18), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [152] = 13,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      sym__let_keyword,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_RBRACE,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(4), 4,
      sym__declaration_statement,
      sym_let_declaration,
      sym_function,
      aux_sym_block_repeat1,
    STATE(18), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [202] = 13,
    ACTIONS(60), 1,
      sym_identifier,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    ACTIONS(65), 1,
      anon_sym_def,
    ACTIONS(68), 1,
      sym__let_keyword,
    ACTIONS(71), 1,
      anon_sym_DASH,
    ACTIONS(74), 1,
      anon_sym_not,
    ACTIONS(83), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_SQUOTE,
    ACTIONS(80), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(77), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(6), 4,
      sym__declaration_statement,
      sym_let_declaration,
      sym_function,
      aux_sym_block_repeat1,
    STATE(18), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [252] = 2,
    ACTIONS(91), 7,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(89), 12,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_STAR_STAR,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [276] = 2,
    ACTIONS(95), 7,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(93), 12,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_STAR_STAR,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [300] = 6,
    ACTIONS(103), 1,
      anon_sym_STAR,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(101), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(105), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(99), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(97), 7,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [332] = 2,
    ACTIONS(111), 7,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(109), 12,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_STAR_STAR,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [356] = 3,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(111), 7,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(109), 11,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [382] = 6,
    ACTIONS(103), 1,
      anon_sym_STAR,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(101), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(105), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(115), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(113), 7,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [414] = 2,
    ACTIONS(119), 7,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(117), 12,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_STAR_STAR,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [438] = 5,
    ACTIONS(103), 1,
      anon_sym_STAR,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(105), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(111), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(109), 9,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [468] = 2,
    ACTIONS(123), 7,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(121), 12,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_STAR_STAR,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [492] = 6,
    ACTIONS(103), 1,
      anon_sym_STAR,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(101), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(105), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(127), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(125), 7,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [524] = 6,
    ACTIONS(103), 1,
      anon_sym_STAR,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(101), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(105), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(129), 6,
      ts_builtin_sym_end,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(131), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
  [555] = 6,
    ACTIONS(103), 1,
      anon_sym_STAR,
    ACTIONS(107), 1,
      anon_sym_STAR_STAR,
    ACTIONS(101), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(105), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(133), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(135), 6,
      anon_sym_RBRACE,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [586] = 5,
    ACTIONS(137), 1,
      sym_identifier,
    ACTIONS(139), 1,
      sym_mutable_modifier,
    STATE(35), 1,
      sym_built_in_type,
    STATE(46), 1,
      sym_type,
    ACTIONS(141), 12,
      anon_sym_byte,
      anon_sym_ushort,
      anon_sym_uint,
      anon_sym_ulong,
      anon_sym_sbyte,
      anon_sym_short,
      anon_sym_int,
      anon_sym_long,
      anon_sym_float,
      anon_sym_double,
      anon_sym_boolean,
      anon_sym_char,
  [613] = 9,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(16), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [648] = 9,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(145), 1,
      sym_identifier,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(12), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [683] = 9,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(10), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [718] = 9,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(149), 1,
      sym_identifier,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(11), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [753] = 9,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(151), 1,
      sym_identifier,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(14), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [788] = 9,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_not,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(153), 1,
      sym_identifier,
    ACTIONS(17), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(8), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(15), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(9), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [823] = 4,
    ACTIONS(137), 1,
      sym_identifier,
    STATE(35), 1,
      sym_built_in_type,
    STATE(48), 1,
      sym_type,
    ACTIONS(141), 12,
      anon_sym_byte,
      anon_sym_ushort,
      anon_sym_uint,
      anon_sym_ulong,
      anon_sym_sbyte,
      anon_sym_short,
      anon_sym_int,
      anon_sym_long,
      anon_sym_float,
      anon_sym_double,
      anon_sym_boolean,
      anon_sym_char,
  [847] = 4,
    ACTIONS(137), 1,
      sym_identifier,
    STATE(35), 1,
      sym_built_in_type,
    STATE(54), 1,
      sym_type,
    ACTIONS(141), 12,
      anon_sym_byte,
      anon_sym_ushort,
      anon_sym_uint,
      anon_sym_ulong,
      anon_sym_sbyte,
      anon_sym_short,
      anon_sym_int,
      anon_sym_long,
      anon_sym_float,
      anon_sym_double,
      anon_sym_boolean,
      anon_sym_char,
  [871] = 2,
    ACTIONS(157), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(155), 8,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [890] = 2,
    ACTIONS(161), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(159), 8,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [909] = 2,
    ACTIONS(165), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(163), 8,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [928] = 2,
    ACTIONS(169), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(167), 8,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [947] = 2,
    ACTIONS(173), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(171), 8,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [966] = 2,
    ACTIONS(177), 6,
      anon_sym_def,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(175), 8,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [985] = 6,
    ACTIONS(179), 1,
      anon_sym_LBRACE,
    ACTIONS(181), 1,
      anon_sym_COLON,
    ACTIONS(183), 1,
      sym__fat_arrow,
    STATE(19), 1,
      sym__colon_symbol,
    STATE(39), 1,
      sym_type_annotation,
    STATE(33), 2,
      sym_block,
      sym_arrow_function_body,
  [1005] = 2,
    ACTIONS(187), 1,
      sym__equals_symbol,
    ACTIONS(185), 4,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym__fat_arrow,
  [1015] = 5,
    ACTIONS(181), 1,
      anon_sym_COLON,
    ACTIONS(189), 1,
      sym__equals_symbol,
    STATE(19), 1,
      sym__colon_symbol,
    STATE(29), 1,
      sym_assignment,
    STATE(51), 1,
      sym_type_annotation,
  [1031] = 2,
    ACTIONS(193), 1,
      sym__equals_symbol,
    ACTIONS(191), 4,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym__fat_arrow,
  [1041] = 3,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    STATE(41), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [1052] = 3,
    ACTIONS(179), 1,
      anon_sym_LBRACE,
    ACTIONS(183), 1,
      sym__fat_arrow,
    STATE(31), 2,
      sym_block,
      sym_arrow_function_body,
  [1063] = 3,
    ACTIONS(197), 1,
      anon_sym_DQUOTE,
    ACTIONS(199), 1,
      anon_sym_SQUOTE,
    STATE(40), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [1074] = 3,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(202), 1,
      anon_sym_DQUOTE,
    STATE(40), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [1085] = 3,
    ACTIONS(204), 1,
      anon_sym_COMMA,
    ACTIONS(206), 1,
      anon_sym_RPAREN,
    STATE(50), 1,
      aux_sym_parameters_repeat1,
  [1095] = 3,
    ACTIONS(208), 1,
      anon_sym_COMMA,
    ACTIONS(211), 1,
      anon_sym_RPAREN,
    STATE(43), 1,
      aux_sym_parameters_repeat1,
  [1105] = 1,
    ACTIONS(213), 3,
      anon_sym_LBRACE,
      anon_sym_COLON,
      sym__fat_arrow,
  [1111] = 3,
    ACTIONS(215), 1,
      sym_identifier,
    ACTIONS(217), 1,
      anon_sym_RPAREN,
    STATE(42), 1,
      sym_parameter,
  [1121] = 2,
    ACTIONS(221), 1,
      sym__equals_symbol,
    ACTIONS(219), 2,
      anon_sym_LBRACE,
      sym__fat_arrow,
  [1129] = 1,
    ACTIONS(223), 3,
      anon_sym_LBRACE,
      anon_sym_COLON,
      sym__fat_arrow,
  [1135] = 2,
    ACTIONS(227), 1,
      sym__equals_symbol,
    ACTIONS(225), 2,
      anon_sym_LBRACE,
      sym__fat_arrow,
  [1143] = 1,
    ACTIONS(229), 3,
      anon_sym_LBRACE,
      anon_sym_COLON,
      sym__fat_arrow,
  [1149] = 3,
    ACTIONS(204), 1,
      anon_sym_COMMA,
    ACTIONS(231), 1,
      anon_sym_RPAREN,
    STATE(43), 1,
      aux_sym_parameters_repeat1,
  [1159] = 2,
    ACTIONS(189), 1,
      sym__equals_symbol,
    STATE(30), 1,
      sym_assignment,
  [1166] = 2,
    ACTIONS(233), 1,
      anon_sym_LPAREN,
    STATE(34), 1,
      sym_parameters,
  [1173] = 2,
    ACTIONS(235), 1,
      sym_character_literal_unescaped,
    ACTIONS(237), 1,
      sym_escape_sequence,
  [1180] = 1,
    ACTIONS(239), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1185] = 1,
    ACTIONS(211), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1190] = 2,
    ACTIONS(215), 1,
      sym_identifier,
    STATE(55), 1,
      sym_parameter,
  [1197] = 1,
    ACTIONS(241), 1,
      ts_builtin_sym_end,
  [1201] = 1,
    ACTIONS(243), 1,
      anon_sym_COLON,
  [1205] = 1,
    ACTIONS(245), 1,
      anon_sym_SQUOTE,
  [1209] = 1,
    ACTIONS(247), 1,
      sym_identifier,
  [1213] = 1,
    ACTIONS(249), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 51,
  [SMALL_STATE(4)] = 102,
  [SMALL_STATE(5)] = 152,
  [SMALL_STATE(6)] = 202,
  [SMALL_STATE(7)] = 252,
  [SMALL_STATE(8)] = 276,
  [SMALL_STATE(9)] = 300,
  [SMALL_STATE(10)] = 332,
  [SMALL_STATE(11)] = 356,
  [SMALL_STATE(12)] = 382,
  [SMALL_STATE(13)] = 414,
  [SMALL_STATE(14)] = 438,
  [SMALL_STATE(15)] = 468,
  [SMALL_STATE(16)] = 492,
  [SMALL_STATE(17)] = 524,
  [SMALL_STATE(18)] = 555,
  [SMALL_STATE(19)] = 586,
  [SMALL_STATE(20)] = 613,
  [SMALL_STATE(21)] = 648,
  [SMALL_STATE(22)] = 683,
  [SMALL_STATE(23)] = 718,
  [SMALL_STATE(24)] = 753,
  [SMALL_STATE(25)] = 788,
  [SMALL_STATE(26)] = 823,
  [SMALL_STATE(27)] = 847,
  [SMALL_STATE(28)] = 871,
  [SMALL_STATE(29)] = 890,
  [SMALL_STATE(30)] = 909,
  [SMALL_STATE(31)] = 928,
  [SMALL_STATE(32)] = 947,
  [SMALL_STATE(33)] = 966,
  [SMALL_STATE(34)] = 985,
  [SMALL_STATE(35)] = 1005,
  [SMALL_STATE(36)] = 1015,
  [SMALL_STATE(37)] = 1031,
  [SMALL_STATE(38)] = 1041,
  [SMALL_STATE(39)] = 1052,
  [SMALL_STATE(40)] = 1063,
  [SMALL_STATE(41)] = 1074,
  [SMALL_STATE(42)] = 1085,
  [SMALL_STATE(43)] = 1095,
  [SMALL_STATE(44)] = 1105,
  [SMALL_STATE(45)] = 1111,
  [SMALL_STATE(46)] = 1121,
  [SMALL_STATE(47)] = 1129,
  [SMALL_STATE(48)] = 1135,
  [SMALL_STATE(49)] = 1143,
  [SMALL_STATE(50)] = 1149,
  [SMALL_STATE(51)] = 1159,
  [SMALL_STATE(52)] = 1166,
  [SMALL_STATE(53)] = 1173,
  [SMALL_STATE(54)] = 1180,
  [SMALL_STATE(55)] = 1185,
  [SMALL_STATE(56)] = 1190,
  [SMALL_STATE(57)] = 1197,
  [SMALL_STATE(58)] = 1201,
  [SMALL_STATE(59)] = 1205,
  [SMALL_STATE(60)] = 1209,
  [SMALL_STATE(61)] = 1213,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [27] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(17),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(60),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(61),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(21),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(21),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(38),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(53),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(18),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(60),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(61),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(21),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(21),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(8),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(8),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(38),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2), SHIFT_REPEAT(53),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arrow_function_body, 2),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arrow_function_body, 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_literal, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 2),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment, 2),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 1),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 3),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 3),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 4),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 4),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 5, .production_id = 2),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function, 5, .production_id = 2),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 4, .production_id = 1),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function, 4, .production_id = 1),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_built_in_type, 1),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_built_in_type, 1),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(53),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [208] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2), SHIFT_REPEAT(56),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 2),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_annotation, 2),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 4),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 3),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_annotation, 3),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [241] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_xva(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
