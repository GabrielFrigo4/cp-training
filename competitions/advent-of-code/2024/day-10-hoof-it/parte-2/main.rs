use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::collections::{HashSet, VecDeque};

fn char_to_u8(c: char) -> u8 {
	if c == '.' {
		return u8::MAX;
	}
	c.to_string().parse::<u8>().unwrap()
}

fn get_pos(mat: &Vec<Vec<u8>>, y: isize, x: isize) -> u8 {
	if y <= -1 || x <= -1 || y >= mat.len() as isize || x >= mat[0].len() as isize {
		return u8::MAX;
	}
	mat[y as usize][x as usize]
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut heads = Vec::<(isize, isize)>::new();
	let mut mat = Vec::<Vec<u8>>::new();
	for (y, line) in reader.lines().enumerate() {
		let line = line.unwrap();
		mat.push(Vec::<u8>::new());
		for (x, c) in line.chars().enumerate() {
			mat[y].push(char_to_u8(c));
			if mat[y][x] == 0 {
				heads.push((y as isize, x as isize));
			}
		}
	}

	let mut sum = 0;
	let mut rep = HashSet::<(isize, isize)>::new();
	let mut fila = VecDeque::<(isize, isize, bool)>::new();
	let movs = [(0, 1), (0, -1), (1, 0), (-1, 0)];
	for (y0, x0) in heads {
		rep.clear();
		fila.clear();
		fila.push_back((y0, x0, false));

		while !fila.is_empty() {
			let front = fila.pop_front().unwrap();
			if get_pos(&mat, front.0, front.1) == 9 {
				sum += front.2 as isize;
				continue;
			}

			for mov in movs {
				if get_pos(&mat, front.0 + mov.0, front.1 + mov.1) == get_pos(&mat, front.0, front.1) + 1 {
					if !rep.contains(&(front.0 + mov.0, front.1 + mov.1)) {
						rep.insert((front.0 + mov.0, front.1 + mov.1));
						fila.push_back((front.0 + mov.0, front.1 + mov.1, true));
					}
					else {
						fila.push_back((front.0 + mov.0, front.1 + mov.1, front.2));
					}
				}
			}
		}
	}

	println!("{}", sum);
}
