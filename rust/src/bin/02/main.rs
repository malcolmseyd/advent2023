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
        let line_pattern = Regex::new(r#"^Game (\d+):"#)?;
        let color_pattern = Regex::new(r#"(\d+) (\w+)"#)?;

        let mut ans = 0;
        for line in input.lines() {
            let game = line.split(':').nth(1).context("missing colon")?;

            let mut possible = true;
            for captures in color_pattern.captures_iter(game) {
                let num: u64 = captures[1]
                    .parse()
                    .context(anyhow!("invalid num: {:?}", &captures[2]))?;
                let color: &str = &captures[2];

                let limit = match color {
                    "red" => 12,
                    "green" => 13,
                    "blue" => 14,
                    c => bail!("unknown color {:?}", c),
                };
                if num > limit {
                    possible = false;
                    break;
                }
            }
            if possible {
                let captures = line_pattern.captures(line).context("missing game info")?;
                let id: u64 = captures[1].parse()?;
                ans += id;
            }
        }
        Ok(ans)
    }
}

mod b {
    #![allow(unused)]
    use anyhow::{anyhow, bail, Context};
    use regex::Regex;

    pub fn solve(input: String) -> anyhow::Result<u64> {
        let line_pattern = Regex::new(r#"^Game (\d+):"#)?;
        let color_pattern = Regex::new(r#"(\d+) (\w+)"#)?;

        let mut ans = 0;
        for line in input.lines() {
            let game = line.split(':').nth(1).context("missing colon")?;

            let mut possible = true;
            let mut max_red = 0;
            let mut max_green = 0;
            let mut max_blue = 0;
            for captures in color_pattern.captures_iter(game) {
                let num: u64 = captures[1]
                    .parse()
                    .context(anyhow!("invalid num: {:?}", &captures[2]))?;
                let color: &str = &captures[2];

                match color {
                    "red" => max_red = max_red.max(num),
                    "green" => max_green = max_green.max(num),
                    "blue" => max_blue = max_blue.max(num),
                    c => bail!("unknown color {:?}", c),
                };
            }
            ans += max_red * max_green * max_blue;
        }
        Ok(ans)
    }
}
