#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 8
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 11
#define ALIAS_COUNT 0
#define TOKEN_COUNT 7
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 1

enum {
  sym_identifier = 1,
  sym_hex_literal = 2,
  sym_octal_literal = 3,
  sym_binary_literal = 4,
  sym_decimal_literal = 5,
  sym_boolean_literal = 6,
  sym_source_file = 7,
  sym_expression = 8,
  sym_literal = 9,
  aux_sym_source_file_repeat1 = 10,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_hex_literal] = "hex_literal",
  [sym_octal_literal] = "octal_literal",
  [sym_binary_literal] = "binary_literal",
  [sym_decimal_literal] = "decimal_literal",
  [sym_boolean_literal] = "boolean_literal",
  [sym_source_file] = "source_file",
  [sym_expression] = "expression",
  [sym_literal] = "literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_hex_literal] = sym_hex_literal,
  [sym_octal_literal] = sym_octal_literal,
  [sym_binary_literal] = sym_binary_literal,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_source_file] = sym_source_file,
  [sym_expression] = sym_expression,
  [sym_literal] = sym_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      if (lookahead == '0') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 1:
      if (lookahead == '_') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == '_') ADVANCE(6);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(12);
      END_STATE();
    case 5:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(2);
      END_STATE();
    case 6:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(14);
      END_STATE();
    case 7:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(3);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(13);
      END_STATE();
    case 9:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(4);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(12);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_hex_literal);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_octal_literal);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_binary_literal);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == '_') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(5);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(7);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(9);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
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
      if (lookahead == 'f') ADVANCE(1);
      if (lookahead == 't') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(3);
      END_STATE();
    case 2:
      if (lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == 'l') ADVANCE(5);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(6);
      END_STATE();
    case 5:
      if (lookahead == 's') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_boolean_literal);
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_hex_literal] = ACTIONS(1),
    [sym_octal_literal] = ACTIONS(1),
    [sym_binary_literal] = ACTIONS(1),
    [sym_decimal_literal] = ACTIONS(1),
    [sym_boolean_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(7),
    [sym_expression] = STATE(2),
    [sym_literal] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
    [sym_hex_literal] = ACTIONS(7),
    [sym_octal_literal] = ACTIONS(7),
    [sym_binary_literal] = ACTIONS(7),
    [sym_decimal_literal] = ACTIONS(9),
    [sym_boolean_literal] = ACTIONS(9),
  },
  [2] = {
    [sym_expression] = STATE(3),
    [sym_literal] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_identifier] = ACTIONS(5),
    [sym_hex_literal] = ACTIONS(7),
    [sym_octal_literal] = ACTIONS(7),
    [sym_binary_literal] = ACTIONS(7),
    [sym_decimal_literal] = ACTIONS(9),
    [sym_boolean_literal] = ACTIONS(9),
  },
  [3] = {
    [sym_expression] = STATE(3),
    [sym_literal] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_identifier] = ACTIONS(15),
    [sym_hex_literal] = ACTIONS(18),
    [sym_octal_literal] = ACTIONS(18),
    [sym_binary_literal] = ACTIONS(18),
    [sym_decimal_literal] = ACTIONS(21),
    [sym_boolean_literal] = ACTIONS(21),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(24),
    [sym_identifier] = ACTIONS(26),
    [sym_hex_literal] = ACTIONS(24),
    [sym_octal_literal] = ACTIONS(24),
    [sym_binary_literal] = ACTIONS(24),
    [sym_decimal_literal] = ACTIONS(26),
    [sym_boolean_literal] = ACTIONS(26),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(28),
    [sym_identifier] = ACTIONS(30),
    [sym_hex_literal] = ACTIONS(28),
    [sym_octal_literal] = ACTIONS(28),
    [sym_binary_literal] = ACTIONS(28),
    [sym_decimal_literal] = ACTIONS(30),
    [sym_boolean_literal] = ACTIONS(30),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(28),
    [sym_identifier] = ACTIONS(30),
    [sym_hex_literal] = ACTIONS(28),
    [sym_octal_literal] = ACTIONS(28),
    [sym_binary_literal] = ACTIONS(28),
    [sym_decimal_literal] = ACTIONS(30),
    [sym_boolean_literal] = ACTIONS(30),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [26] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [30] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [32] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
