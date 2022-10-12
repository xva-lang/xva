use crate::constants;

pub struct EvaluationStack {
    data: Vec<u8>,
    stack_pointer: i32,
    max_length: usize,
}

pub fn stack_create(size: usize) -> EvaluationStack {
    EvaluationStack {
        data: vec![0; size],
        stack_pointer: -1,
        max_length: size,
    }
}

pub fn stack_push(stack: &mut EvaluationStack, value: u8) {
    if stack.stack_pointer >= 0 {
        if stack.stack_pointer as usize >= stack.max_length {
            println!("Stack overflow!");
            std::process::exit(constants::ErrorCodes::StackOverflow as i32);
        }
    }

    stack.stack_pointer += 1;
    stack.data[stack.stack_pointer as usize] = value;
}

pub fn dump_stack(stack: &EvaluationStack) {
    const MAX_COLUMN: usize = 16;
    let rows = (stack.stack_pointer / MAX_COLUMN as i32) + 1;
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
            let index: usize = (row as usize * MAX_COLUMN) + column;
            if index >= stack.data.len() {
                break;
            }
            let data_item = format!("{:02x}   ", stack.data[index]);
            row_content.push_str(data_item.as_str());
        }

        println!("{}", row_content);
    }
}

impl EvaluationStack {
    pub fn push_uint8(&mut self, value: u8) {
        stack_push(self, value as u8);
    }

    pub fn push_uint16(&mut self, value: u16) {
        let bytes = spread_bytes(value as u64, 2);
        for byte in bytes.iter() {
            stack_push(self, *byte);
        }
    }

    pub fn push_uint32(&mut self, value: u32) {
        let bytes = spread_bytes(value as u64, 4);
        for byte in bytes.iter() {
            stack_push(self, *byte);
        }
    }

    // pub fn push_uint64(&mut self, value: u64) {
    //     let bytes = spread_bytes(value as u64, 8);
    //     for byte in bytes.iter() {
    //         stack_push(self, *byte);
    //     }
    // }

    pub fn pop_byte(&mut self) -> u8 {
        let result: u8 = self.data[self.stack_pointer as usize];
        self.stack_pointer -= 1;
        result
    }
}

// pub fn push_float(stack: &mut EvaluationStack, value: f32) {
//     let bytes = unsafe { std::mem::transmute::<f32, [u8; 4]>(value) };
//     for i in 0..4 {
//         stack_push(stack, bytes[i]);
//     }
// }

// pub fn push_double(stack: &mut EvaluationStack, value: f64) {
//     let bytes = unsafe { std::mem::transmute::<f64, [u8; 8]>(value) };
//     for i in 0..8 {
//         stack_push(stack, bytes[i]);
//     }
// }

pub fn spread_bytes(value: u64, byte_size: usize) -> Vec<u8> {
    let mut result: Vec<u8> = vec![0; byte_size as usize];
    for i in 0..byte_size {
        result[i as usize] = ((value as u64 & (0xff << (i * 8))) >> ((i * 8) as u64)) as u8;
    }
    return result;
}

pub fn combine_bytes_u16(values: [u8; 2]) -> u16 {
    ((values[0] as u16) << 8 | values[1] as u16) as u16
}

pub fn combine_bytes_u32(values: [u8; 4]) -> u32 {
    let mut result: u32 = 0;
    for i in 0..4 {
        result += (values[i] as u32) << ((3 - i) * 8);
    }
    result
}

// pub fn combine_bytes_u64(values: [u8; 8]) -> u64 {
//     (values[0] << 56
//         | values[1] << 48
//         | values[2] << 40
//         | values[3] << 32
//         | values[4] << 24
//         | values[5] << 16
//         | values[6] << 8
//         | values[7]) as u64
// }
