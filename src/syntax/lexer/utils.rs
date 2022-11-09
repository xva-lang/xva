pub(crate) fn input_lines_as_vec(input: &str) -> Vec<&str> {
    input.split("\n").collect()
}

pub(crate) fn string_lines_as_vec(input: String) -> Vec<String> {
    let mut result: Vec<String> = vec![];
    for line in input.split("\n") {
        result.push(String::from(line));
    }

    result
}

pub(crate) fn string_lines_with_original(input: String) -> (Vec<String>, String) {
    let mut result: Vec<String> = vec![];
    for line in input.split("\n") {
        result.push(String::from(line));
    }

    (result, String::from(input))
}
