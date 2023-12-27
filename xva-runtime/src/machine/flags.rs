pub(super) enum Flag {
    Zero,
    Sign,
}

const FLAG_ZERO: u32 = 1;
const FLAG_SIGN: u32 = 1 << 2;

impl From<Flag> for u32 {
    #[inline]
    fn from(flag: Flag) -> Self {
        match flag {
            Flag::Zero => FLAG_ZERO,
            Flag::Sign => FLAG_SIGN,
        }
    }
}

pub(super) struct FlagsRegister {
    internal_flags: u32,
}

impl FlagsRegister {
    pub(super) fn new() -> Self {
        Self { internal_flags: 0 }
    }

    #[inline]
    pub(super) fn set_flag(&mut self, flag: Flag) {
        self.internal_flags = self.internal_flags | u32::from(flag);
    }

    #[inline]
    pub(super) fn is_flag_set(&self, flag: Flag) -> bool {
        self.internal_flags & u32::from(flag) != 0
    }
}
