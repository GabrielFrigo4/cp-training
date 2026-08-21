use std::env;
use std::fs;

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let mut content = fs::read_to_string(input).unwrap();
	content = content.trim().to_string();

	let mut id = 0;
	let mut mem = Vec::<i32>::new();
	for (i, c) in content.chars().enumerate() {
		let num = c.to_string().parse::<usize>().unwrap();
		if i & 1 == 0 {
			mem.append(&mut vec![id as i32; num]);
			id += 1;
		}
		else {
			mem.append(&mut vec![-1 as i32; num]);
		}
	}

	let mut li = 0;
	let mut ri = mem.len() - 1;
	while li < ri {
		if mem[li] != -1 {
			li += 1;
		}
		if mem[ri] == -1 {
			ri -= 1;
		}

		if mem[li] == -1 && mem[ri] != -1 {
			mem[li] = mem[ri];
			mem[ri] = -1;
			li += 1;
			ri -= 1;
		}
	}

	let mut sum = 0;
	for (i, n) in mem.into_iter().enumerate() {
		if n == -1 {
			break;
		}
		sum += i * n as usize;
	}

	println!("{}", sum);
}
