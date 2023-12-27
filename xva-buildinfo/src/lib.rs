build_info::build_info!(fn build_info);

/// Returns a formatted string containing the current branch and commit ID, the
/// commit timestamp, and the Rust compiler triple for the target.
pub fn get_build_info() -> String {
    let git_info = build_info()
        .version_control
        .as_ref()
        .unwrap()
        .git()
        .unwrap();
    let compiler_triple = &build_info().compiler.host_triple;
    format!(
        "({}/{}, {}) [{}]",
        git_info.branch.as_ref().unwrap(),
        git_info.commit_short_id,
        git_info.commit_timestamp.format("%d %B %Y, %I:%M:%S%p"),
        compiler_triple,
    )
}
