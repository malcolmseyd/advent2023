use std::{
    env::args,
    io::{stdin, Read},
};

use anyhow::bail;

fn main() -> anyhow::Result<()> {
    let mut input: String = String::new();
    stdin().read_to_string(&mut input)?;
    let ans = match args().nth(1) {
        Some(s) if s == "a" => a::solve(input)?,
        Some(s) if s == "b" => b::solve(input)?,
        Some(_) | None => {
            bail!("expected 'a' or 'b'")
        }
    };
    println!("{}", ans);
    Ok(())
}

mod a {
    #![allow(unused)]
    use anyhow::{anyhow, bail, Context};
    use regex::Regex;

    pub fn solve(input: String) -> anyhow::Result<u64> {
        let mut ans = 0;
        for line in input.lines() {
            // TODO
        }
        Ok(ans)
    }
}

mod b {
    #![allow(unused)]
    use anyhow::{anyhow, bail, Context};
    use regex::Regex;

    pub fn solve(input: String) -> anyhow::Result<u64> {
        let mut ans = 0;
        for line in input.lines() {
            // TODO
        }
        Ok(ans)
    }
}
