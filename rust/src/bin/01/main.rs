use std::{env::args, io::stdin};

use anyhow::bail;

fn main() -> anyhow::Result<()> {
    let lines: Vec<String> = stdin().lines().collect::<Result<_, _>>()?;
    let ans = match args().nth(1) {
        Some(s) if s == "a" => a::solve(lines)?,
        Some(s) if s == "b" => b::solve(lines)?,
        Some(_) | None => {
            bail!("expected 'a' or 'b'")
        }
    };
    println!("{}", ans);
    Ok(())
}

mod a {
    use anyhow::anyhow;
    use regex::Regex;

    pub fn solve(lines: Vec<String>) -> anyhow::Result<u64> {
        let number_pattern = Regex::new("[0-9]")?;

        let mut sum: u64 = 0;
        for line in lines {
            let first: u64 = number_pattern
                .find(&line)
                .ok_or_else(|| anyhow!("no number in {:?}", line))?
                .as_str()
                .parse()?;

            let last: u64 = number_pattern
                .find(&line.chars().rev().collect::<String>())
                .ok_or_else(|| anyhow!("no number backwards in {:?}", line))?
                .as_str()
                .parse()?;

            sum += first * 10 + last;
        }
        Ok(sum)
    }
}

mod b {
    use anyhow::{anyhow, bail};
    use regex::Regex;

    fn parse(s: &str) -> anyhow::Result<u64> {
        if let Ok(n) = s.parse::<u64>() {
            return Ok(n);
        }
        Ok(match s {
            "one" => 1,
            "two" => 2,
            "three" => 3,
            "four" => 4,
            "five" => 5,
            "six" => 6,
            "seven" => 7,
            "eight" => 8,
            "nine" => 9,
            s => bail!("invalid number {:?}", s),
        })
    }

    pub fn solve(lines: Vec<String>) -> anyhow::Result<u64> {
        let nums = [
            "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        ]
        .join("|");
        let forward_pattern = Regex::new((nums.clone() + "|[0-9]").as_str())?;
        let backward_pattern =
            Regex::new((nums.chars().rev().collect::<String>() + "|[0-9]").as_str())?;

        let mut sum: u64 = 0;
        for line in lines {
            let first = parse(
                forward_pattern
                    .find(&line)
                    .ok_or_else(|| anyhow!("no number in {:?}", line))?
                    .as_str(),
            )?;

            let last = parse(
                backward_pattern
                    .find(&line.chars().rev().collect::<String>())
                    .ok_or_else(|| anyhow!("no number backwards in {:?}", line))?
                    .as_str()
                    .chars()
                    .rev()
                    .collect::<String>()
                    .as_str(),
            )?;

            sum += first * 10 + last;
        }
        Ok(sum)
    }
}
