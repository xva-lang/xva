use crate::constants;

pub struct EvaluationStack {
    data: Vec<u8>,
    stack_pointer: usize,
    max_length: usize,
}

pub fn stack_create(size: usize) -> EvaluationStack {
    EvaluationStack {
        data: vec![0; size],
        stack_pointer: 0,
        max_length: size,
    }
}

pub fn stack_push(stack: &mut EvaluationStack, value: u8) {
    if stack.stack_pointer >= stack.max_length {
        println!("Stack overflow!");
        std::process::exit(constants::ErrorCodes::StackOverflow as i32);
    } else {
        stack.data[stack.stack_pointer] = value;
        stack.stack_pointer += 1;
    }
}

pub fn dump_stack(stack: &EvaluationStack) {
    println!("Evaluation stack dump\n");
    const MAX_COLUMN: usize = 16;
    let rows = (stack.stack_pointer / MAX_COLUMN as usize) + 1;
    let mut row_header = String::new();
    for column in 0..MAX_COLUMN {
        match std::char::from_digit(column as u32, 16) {
            Some(chr) => {
                let header_item = format!("{}    ", chr);
                row_header.push_str(header_item.as_str());
            }
            None => {}
        }
    }

    println!("            {}", row_header);
    for row in 0..rows {
        let mut row_content = String::new();

        // Width of 9 = 7 chars + "0x"
        row_content.push_str(format!("{:#09x}   ", row).as_str());

        for column in 0..MAX_COLUMN {
            let index = (row * MAX_COLUMN) + column;
            if index >= stack.data.len() {
                break;
            }
            let data_item = format!("{:02x}   ", stack.data[index]);
            row_content.push_str(data_item.as_str());
        }

        println!("{}", row_content);
    }
}

#[allow(dead_code)]
pub fn push_int8(stack: &mut EvaluationStack, value: i8) {
    stack_push(stack, value as u8);
}

#[allow(dead_code)]
pub fn push_int16(stack: &mut EvaluationStack, value: i16) {
    let bytes = spread_bytes(value as u64, 2);
    for byte in bytes.iter() {
        stack_push(stack, *byte);
    }
}

#[allow(dead_code)]
pub fn push_int32(stack: &mut EvaluationStack, value: i32) {
    let bytes = spread_bytes(value as u64, 4);
    for byte in bytes.iter() {
        stack_push(stack, *byte);
    }
}

#[allow(dead_code)]
pub fn push_int64(stack: &mut EvaluationStack, value: i64) {
    let bytes = spread_bytes(value as u64, 8);
    for byte in bytes.iter() {
        stack_push(stack, *byte);
    }
}

#[allow(dead_code)]
pub fn push_boolean(stack: &mut EvaluationStack, value: bool) {
    stack_push(stack, if value { 1 } else { 0 });
}

#[allow(dead_code)]
pub fn push_float(stack: &mut EvaluationStack, value: f32) {
    let bytes = unsafe { std::mem::transmute::<f32, [u8; 4]>(value) };
    for i in 0..4 {
        stack_push(stack, bytes[i]);
    }
}

#[allow(dead_code)]
pub fn push_double(stack: &mut EvaluationStack, value: f64) {
    let bytes = unsafe { std::mem::transmute::<f64, [u8; 8]>(value) };
    for i in 0..8 {
        stack_push(stack, bytes[i]);
    }
}

pub fn spread_bytes(value: u64, byte_size: usize) -> Vec<u8> {
    let mut result: Vec<u8> = vec![0; byte_size as usize];
    for i in 0..byte_size {
        result[i as usize] = ((value as u64 & (0xff << (i * 8))) >> ((i * 8) as u64)) as u8;
    }
    return result;
}
