use serde::Serialize;
use std::path::Path;

use clap::command;
use clap::Args;
use clap::Parser;
use clap::Subcommand;

use crate::repl::repl_main;

#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
#[command(propagate_version = true)]
struct Cli {
    #[command(subcommand)]
    command: Option<Commands>,
}

#[derive(Subcommand, Debug)]
enum Commands {
    /// Creates a new Xva project.
    Init(Init),
}

#[derive(Args, Debug)]
struct Init {
    /// The name of the new project. Creates a directory in the current folder for the new project.
    directory: Option<String>,
}

pub(crate) fn cli() {
    let cli = Cli::parse();

    match cli.command {
        Some(c) => match c {
            Commands::Init(i) => create_project(&i.directory),
        },
        None => match repl_main() {
            Ok(_) => {}
            Err(_) => {}
        },
    }
}

#[derive(Serialize)]
struct ProjectFile {
    project: Project,
}

#[derive(Serialize)]
struct Project {
    name: String,
    version: String,
}

fn create_project(directory: &Option<String>) {
    if directory.is_none() {
        println!("Can't create a Xva project. No directory specified.");
        return;
    }

    let full_path = Path::new(std::env::current_dir().unwrap().as_path())
        .join(Path::new(directory.as_ref().unwrap().as_str()));

    if full_path.exists() {
        println!(
            "Can't create a Xva project in {}. The directory already exists.",
            directory.as_ref().unwrap()
        )
    } else {
        match std::fs::create_dir(full_path.as_path()) {
            Ok(_) => match std::fs::write(
                full_path.join("xvaproj.toml"),
                toml::to_string(&ProjectFile {
                    project: Project {
                        name: String::from(directory.as_ref().unwrap()),
                        version: String::from("0.0.1"),
                    },
                })
                .unwrap()
                .as_str(),
            ) {
                Ok(_) => {}
                Err(e) => {
                    println!("Failed to create the project file. {}", e);
                    return;
                }
            },
            Err(e) => {
                println!("Failed to create the project directory. {}", e)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use std::path::Path;

    #[test]
    fn create_project() {
        super::create_project(&Some(String::from("project")));
        let project_file_path = Path::new(std::env::current_dir().unwrap().as_path())
            .join(Path::new(String::from("project").as_str()))
            .join(Path::new(String::from("xvaproj.toml").as_str()));

        let file_contents = std::fs::read_to_string(project_file_path).unwrap();

        std::fs::remove_dir_all(
            Path::new(std::env::current_dir().unwrap().as_path())
                .join(Path::new(String::from("project").as_str())),
        )
        .unwrap();

        assert_eq!(
            file_contents,
            r#"[project]
name = "project"
version = "0.0.1"
"#
        )
    }
}
