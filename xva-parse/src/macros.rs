#[macro_export]
macro_rules! strings {
    ( $( $i:ident = $l:literal )* ) => {
        $(
            const $i: &str = $l;
        )*
    };
}
