use std::{io::Write, process::Command};

use time::macros::format_description;

// use time::format_description;

fn main() -> std::io::Result<()> {
    println!("cargo:rerun-if-changed=.buildinfo");

    let current_branch_cmd = Command::new("git")
        .args(["rev-parse", "--abbrev-ref", "HEAD"])
        .output()
        .unwrap();

    let branch = std::str::from_utf8(&current_branch_cmd.stdout)
        .unwrap()
        .trim_end();

    let current_commit_cmd = Command::new("git")
        .args(["rev-parse", "--short", "HEAD"])
        .output()
        .unwrap();
    let sha = std::str::from_utf8(&current_commit_cmd.stdout)
        .unwrap()
        .trim_end();

    let package_version = std::env!("CARGO_PKG_VERSION");
    let target = std::env::var("TARGET").unwrap();
    // let rdate = time::
    let build_date = time::OffsetDateTime::now_local().unwrap();

    let mut file = std::fs::OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .open("./.buildinfo")?;

    file.write_all(format!(
        "Xva {package_version} ({branch}/{sha}, {}) [{target}]",
        build_date
            .format(format_description!("[day] [month repr:long] [year padding:zero], [hour padding:zero repr:24]:[minute padding:zero]:[second padding:zero]"))
            .unwrap()
    ).as_bytes())?;

    Ok(())
}
