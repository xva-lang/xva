pub struct Stack<T> {
    data: Vec<T>,
}

#[allow(dead_code)]
impl<T> Stack<T> {
    pub fn new(capacity: usize) -> Stack<T> {
        Stack {
            data: Vec::with_capacity(capacity),
        }
    }

    pub fn push(&mut self, value: T) {
        debug_assert!(self.data.len() <= self.data.capacity(), "Stack overflow!");
        self.data.push(value);
    }

    pub fn pop(&mut self) -> T {
        self.data.pop().unwrap()
    }

    pub fn pop_bytes(&mut self, size: usize) -> Vec<T> {
        let mut result = Vec::with_capacity(size);
        for _ in 0..size {
            result.push(self.pop());
        }

        result
    }

    pub fn peek_top(&mut self) -> &T {
        &self.data[self.data.len() - 1]
    }

    pub fn peek_at(&mut self, index: usize) -> &T {
        &self.data[index]
    }
}
