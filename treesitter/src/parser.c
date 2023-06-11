#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  sym_identifier = 1,
  sym_mutable_modifier = 2,
  sym__colon_symbol = 3,
  sym__equals_symbol = 4,
  sym__let_keyword = 5,
  anon_sym_byte = 6,
  anon_sym_ushort = 7,
  anon_sym_uint = 8,
  anon_sym_ulong = 9,
  anon_sym_sbyte = 10,
  anon_sym_short = 11,
  anon_sym_int = 12,
  anon_sym_long = 13,
  anon_sym_float = 14,
  anon_sym_double = 15,
  anon_sym_boolean = 16,
  anon_sym_char = 17,
  anon_sym_DASH = 18,
  anon_sym_not = 19,
  anon_sym_PLUS = 20,
  anon_sym_STAR = 21,
  anon_sym_SLASH = 22,
  anon_sym_PERCENT = 23,
  anon_sym_STAR_STAR = 24,
  sym_hex_literal = 25,
  sym_octal_literal = 26,
  sym_binary_literal = 27,
  sym_decimal_literal = 28,
  sym_boolean_literal = 29,
  anon_sym_DQUOTE = 30,
  anon_sym_SQUOTE = 31,
  sym_character_literal_unescaped = 32,
  sym_escape_sequence = 33,
  sym_source_file = 34,
  sym__statement = 35,
  sym__declaration_statement = 36,
  sym_let_declaration = 37,
  sym_assignment = 38,
  sym_type_annotation = 39,
  sym_type = 40,
  sym_built_in_type = 41,
  sym__expression = 42,
  sym_unary_expression = 43,
  sym_binary_expression = 44,
  sym_string_literal = 45,
  sym_character_literal = 46,
  sym_literal = 47,
  aux_sym_source_file_repeat1 = 48,
  aux_sym_string_literal_repeat1 = 49,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_mutable_modifier] = "mutable_modifier",
  [sym__colon_symbol] = "_colon_symbol",
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
  [sym_type] = "type",
  [sym_built_in_type] = "built_in_type",
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_string_literal] = "string_literal",
  [sym_character_literal] = "character_literal",
  [sym_literal] = "literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_mutable_modifier] = sym_mutable_modifier,
  [sym__colon_symbol] = sym__colon_symbol,
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
  [sym_type] = sym_type,
  [sym_built_in_type] = sym_built_in_type,
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_string_literal] = sym_string_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_literal] = sym_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [sym_mutable_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__colon_symbol] = {
    .visible = false,
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
  [sym_type] = {
    .visible = true,
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
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '"') ADVANCE(36);
      if (lookahead == '%') ADVANCE(29);
      if (lookahead == '\'') ADVANCE(37);
      if (lookahead == '*') ADVANCE(27);
      if (lookahead == '+') ADVANCE(26);
      if (lookahead == '-') ADVANCE(25);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == '0') ADVANCE(35);
      if (lookahead == ':') ADVANCE(23);
      if (lookahead == '=') ADVANCE(24);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(34);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 1:
      if (lookahead == 'U') ADVANCE(21);
      if (lookahead == 'u') ADVANCE(17);
      if (lookahead == 'x') ADVANCE(13);
      if (lookahead != 0) ADVANCE(39);
      END_STATE();
    case 2:
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(38);
      END_STATE();
    case 3:
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 4:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(32);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 7:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(33);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(5);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(32);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(6);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(16);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
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
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym__colon_symbol);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym__equals_symbol);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(30);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_hex_literal);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_octal_literal);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_binary_literal);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(7);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(9);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(12);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_character_literal_unescaped);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
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
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(16);
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 5:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(19);
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 7:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == 'b') ADVANCE(23);
      if (lookahead == 'h') ADVANCE(24);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(26);
      if (lookahead == 'l') ADVANCE(27);
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 'o') ADVANCE(29);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 15:
      if (lookahead == 'u') ADVANCE(32);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 20:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 23:
      if (lookahead == 'y') ADVANCE(40);
      END_STATE();
    case 24:
      if (lookahead == 'o') ADVANCE(41);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(42);
      END_STATE();
    case 26:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 27:
      if (lookahead == 'o') ADVANCE(44);
      END_STATE();
    case 28:
      if (lookahead == 'h') ADVANCE(45);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(46);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 32:
      if (lookahead == 'b') ADVANCE(49);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(50);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(51);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__let_keyword);
      END_STATE();
    case 37:
      if (lookahead == 'g') ADVANCE(52);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 40:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 41:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 43:
      if (lookahead == 't') ADVANCE(57);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 49:
      if (lookahead == 'l') ADVANCE(61);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(62);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_long);
      END_STATE();
    case 53:
      if (lookahead == 'b') ADVANCE(63);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(65);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_boolean_literal);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_uint);
      END_STATE();
    case 58:
      if (lookahead == 'g') ADVANCE(66);
      END_STATE();
    case 59:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 60:
      if (lookahead == 'a') ADVANCE(68);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_sbyte);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_short);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_ulong);
      END_STATE();
    case 67:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(72);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_double);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_ushort);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 73:
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
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_mutable_modifier] = ACTIONS(1),
    [sym__colon_symbol] = ACTIONS(1),
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
    [sym_source_file] = STATE(34),
    [sym__statement] = STATE(3),
    [sym__declaration_statement] = STATE(3),
    [sym_let_declaration] = STATE(3),
    [sym__expression] = STATE(8),
    [sym_unary_expression] = STATE(8),
    [sym_binary_expression] = STATE(8),
    [sym_string_literal] = STATE(13),
    [sym_character_literal] = STATE(13),
    [sym_literal] = STATE(8),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
    [sym__let_keyword] = ACTIONS(7),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_not] = ACTIONS(11),
    [sym_hex_literal] = ACTIONS(13),
    [sym_octal_literal] = ACTIONS(13),
    [sym_binary_literal] = ACTIONS(13),
    [sym_decimal_literal] = ACTIONS(15),
    [sym_boolean_literal] = ACTIONS(15),
    [anon_sym_DQUOTE] = ACTIONS(17),
    [anon_sym_SQUOTE] = ACTIONS(19),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      sym_identifier,
    ACTIONS(26), 1,
      sym__let_keyword,
    ACTIONS(29), 1,
      anon_sym_DASH,
    ACTIONS(32), 1,
      anon_sym_not,
    ACTIONS(41), 1,
      anon_sym_DQUOTE,
    ACTIONS(44), 1,
      anon_sym_SQUOTE,
    ACTIONS(38), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(35), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(2), 4,
      sym__statement,
      sym__declaration_statement,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
    STATE(8), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [47] = 12,
    ACTIONS(5), 1,
      sym_identifier,
    ACTIONS(7), 1,
      sym__let_keyword,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_not,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(13), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(2), 4,
      sym__statement,
      sym__declaration_statement,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
    STATE(8), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [94] = 3,
    ACTIONS(53), 1,
      anon_sym_STAR_STAR,
    ACTIONS(51), 6,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(49), 10,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [118] = 6,
    ACTIONS(53), 1,
      anon_sym_STAR_STAR,
    ACTIONS(61), 1,
      anon_sym_STAR,
    ACTIONS(59), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(57), 5,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(55), 6,
      ts_builtin_sym_end,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [148] = 2,
    ACTIONS(67), 6,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(65), 11,
      ts_builtin_sym_end,
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
  [170] = 2,
    ACTIONS(51), 6,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(49), 11,
      ts_builtin_sym_end,
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
  [192] = 6,
    ACTIONS(53), 1,
      anon_sym_STAR_STAR,
    ACTIONS(61), 1,
      anon_sym_STAR,
    ACTIONS(59), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(71), 5,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(69), 6,
      ts_builtin_sym_end,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [222] = 5,
    ACTIONS(53), 1,
      anon_sym_STAR_STAR,
    ACTIONS(61), 1,
      anon_sym_STAR,
    ACTIONS(63), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(51), 5,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(49), 8,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [250] = 2,
    ACTIONS(75), 6,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(73), 11,
      ts_builtin_sym_end,
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
  [272] = 6,
    ACTIONS(53), 1,
      anon_sym_STAR_STAR,
    ACTIONS(61), 1,
      anon_sym_STAR,
    ACTIONS(59), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(79), 5,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(77), 6,
      ts_builtin_sym_end,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [302] = 2,
    ACTIONS(83), 6,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(81), 11,
      ts_builtin_sym_end,
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
  [324] = 2,
    ACTIONS(87), 6,
      sym__let_keyword,
      anon_sym_not,
      anon_sym_STAR,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(85), 11,
      ts_builtin_sym_end,
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
  [346] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_not,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(15), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(13), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(5), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [381] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_not,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(91), 1,
      sym_identifier,
    ACTIONS(15), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(13), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(11), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [416] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_not,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(93), 1,
      sym_identifier,
    ACTIONS(15), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(13), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(9), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [451] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_not,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(95), 1,
      sym_identifier,
    ACTIONS(15), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(13), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(4), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [486] = 9,
    ACTIONS(9), 1,
      anon_sym_DASH,
    ACTIONS(11), 1,
      anon_sym_not,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(15), 2,
      sym_decimal_literal,
      sym_boolean_literal,
    STATE(13), 2,
      sym_string_literal,
      sym_character_literal,
    ACTIONS(13), 3,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
    STATE(7), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
  [521] = 5,
    ACTIONS(99), 1,
      sym_identifier,
    ACTIONS(101), 1,
      sym_mutable_modifier,
    STATE(32), 1,
      sym_built_in_type,
    STATE(33), 1,
      sym_type,
    ACTIONS(103), 12,
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
  [548] = 4,
    ACTIONS(99), 1,
      sym_identifier,
    STATE(32), 1,
      sym_built_in_type,
    STATE(35), 1,
      sym_type,
    ACTIONS(103), 12,
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
  [572] = 2,
    ACTIONS(107), 5,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(105), 7,
      ts_builtin_sym_end,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [589] = 2,
    ACTIONS(111), 5,
      sym__let_keyword,
      anon_sym_not,
      sym_decimal_literal,
      sym_boolean_literal,
      sym_identifier,
    ACTIONS(109), 7,
      ts_builtin_sym_end,
      anon_sym_DASH,
      sym_hex_literal,
      sym_octal_literal,
      sym_binary_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [606] = 4,
    ACTIONS(113), 1,
      sym__colon_symbol,
    ACTIONS(115), 1,
      sym__equals_symbol,
    STATE(22), 1,
      sym_assignment,
    STATE(28), 1,
      sym_type_annotation,
  [619] = 3,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(117), 1,
      anon_sym_DQUOTE,
    STATE(25), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [630] = 3,
    ACTIONS(119), 1,
      anon_sym_DQUOTE,
    ACTIONS(121), 1,
      anon_sym_SQUOTE,
    STATE(25), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [641] = 3,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(124), 1,
      anon_sym_DQUOTE,
    STATE(24), 2,
      sym_character_literal,
      aux_sym_string_literal_repeat1,
  [652] = 2,
    ACTIONS(126), 1,
      sym_character_literal_unescaped,
    ACTIONS(128), 1,
      sym_escape_sequence,
  [659] = 2,
    ACTIONS(115), 1,
      sym__equals_symbol,
    STATE(21), 1,
      sym_assignment,
  [666] = 1,
    ACTIONS(130), 1,
      sym_identifier,
  [670] = 1,
    ACTIONS(132), 1,
      anon_sym_SQUOTE,
  [674] = 1,
    ACTIONS(134), 1,
      sym__equals_symbol,
  [678] = 1,
    ACTIONS(136), 1,
      sym__equals_symbol,
  [682] = 1,
    ACTIONS(138), 1,
      sym__equals_symbol,
  [686] = 1,
    ACTIONS(140), 1,
      ts_builtin_sym_end,
  [690] = 1,
    ACTIONS(142), 1,
      sym__equals_symbol,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 94,
  [SMALL_STATE(5)] = 118,
  [SMALL_STATE(6)] = 148,
  [SMALL_STATE(7)] = 170,
  [SMALL_STATE(8)] = 192,
  [SMALL_STATE(9)] = 222,
  [SMALL_STATE(10)] = 250,
  [SMALL_STATE(11)] = 272,
  [SMALL_STATE(12)] = 302,
  [SMALL_STATE(13)] = 324,
  [SMALL_STATE(14)] = 346,
  [SMALL_STATE(15)] = 381,
  [SMALL_STATE(16)] = 416,
  [SMALL_STATE(17)] = 451,
  [SMALL_STATE(18)] = 486,
  [SMALL_STATE(19)] = 521,
  [SMALL_STATE(20)] = 548,
  [SMALL_STATE(21)] = 572,
  [SMALL_STATE(22)] = 589,
  [SMALL_STATE(23)] = 606,
  [SMALL_STATE(24)] = 619,
  [SMALL_STATE(25)] = 630,
  [SMALL_STATE(26)] = 641,
  [SMALL_STATE(27)] = 652,
  [SMALL_STATE(28)] = 659,
  [SMALL_STATE(29)] = 666,
  [SMALL_STATE(30)] = 670,
  [SMALL_STATE(31)] = 674,
  [SMALL_STATE(32)] = 678,
  [SMALL_STATE(33)] = 682,
  [SMALL_STATE(34)] = 686,
  [SMALL_STATE(35)] = 690,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(29),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(15),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(15),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(27),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 2),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment, 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_literal, 3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 4),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 4),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 3),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(27),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_built_in_type, 1),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 2),
  [140] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 3),
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
