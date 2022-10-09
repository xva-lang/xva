mod constants;
mod machine;
use machine::stack;
mod repl;

fn main() {
    // repl::repl_loop();
    const STACK_SIZE: u8 = 32;
    let mut stack = stack::stack_create(STACK_SIZE as usize);

    stack::push_float(&mut stack, 0.123);
    stack::dump_stack(&stack);
}
