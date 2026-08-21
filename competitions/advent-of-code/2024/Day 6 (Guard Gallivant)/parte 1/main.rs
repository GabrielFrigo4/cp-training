use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

#[derive(PartialEq)]
enum Symbol {
	Obstacle,
	Used,
	Free,
}

fn char_symbol(c: char) -> Symbol {
	match c {
		'#' => Symbol::Obstacle,
		_ => Symbol::Free
	}
}

fn valid_pos(x: isize, y: isize, mat: &Vec::<Vec<Symbol>>) -> bool {
	return !(y < 0 || x < 0 || y >= mat.len() as isize || x >= mat[0].len() as isize);
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut pos = (0, 0);
	let mut dir = (-1, 0);

	let mut mat = Vec::<Vec<Symbol>>::new();
	for (index_y, line) in reader.lines().enumerate() {
		let line = line.unwrap();
		mat.push(line.chars().map(|x| char_symbol(x)).collect::<Vec<Symbol>>());
		for (index_x, char) in line.chars().enumerate() {
			if pos != (0, 0) {
				break;
			}
			if char == '^' {
				pos = (index_y as isize, index_x as isize);
			}
		}
	}

	let mut count = 0;
	loop {
		if mat[pos.0 as usize][pos.1 as usize] == Symbol::Free {
			mat[pos.0 as usize][pos.1 as usize] = Symbol::Used;
			count += 1;
		}

		if !valid_pos(pos.1 + dir.1, pos.0 + dir.0, &mat) {
			break;
		}

		if mat[(pos.0 + dir.0) as usize][(pos.1 + dir.1) as usize] != Symbol::Obstacle {
			pos.0 += dir.0;
			pos.1 += dir.1;
			continue;
		}

		match dir {
			(-1, 0) => dir = (0, 1),
			(0, 1) => dir = (1, 0),
			(1, 0) => dir = (0, -1),
			(0, -1) => dir = (-1, 0),
			_ => ()
		};
	}
	println!("{}", count);
}
