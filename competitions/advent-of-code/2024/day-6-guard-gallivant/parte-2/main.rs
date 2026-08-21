use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

#[derive(Eq, Hash, PartialEq)]
enum Symbol {
	Obstacle,
	Free
}

fn char_symbol(c: char) -> Symbol {
	match c {
		'#' => Symbol::Obstacle,
		_ => Symbol::Free
	}
}

fn next_dir(d: (isize, isize)) -> (isize, isize) {
	match d {
		(-1, 0) => (0, 1),
		(0, 1) => (1, 0),
		(1, 0) => (0, -1),
		(0, -1) => (-1, 0),
		_ => (0, 0)
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
			if char == '^' {
				pos = (index_y as isize, index_x as isize);
			}
		}
	}

	let init_pos = pos;
	let init_dir = dir;

	let mut count = 0;
	for y in 0..mat.len() {
		for x in 0..mat[y].len() {
			if mat[y][x] == Symbol::Obstacle {
				continue;
			}
			mat[y][x] = Symbol::Obstacle;

			pos = init_pos;
			dir = init_dir;
			let mut energy = (mat.len() * mat[y].len()) as isize;
			while valid_pos(pos.1 + dir.1, pos.0 + dir.0, &mat) {
				energy -= 1;
				if energy < 0 {
					count += 1;
					break;
				}
				if mat[(pos.0 + dir.0) as usize][(pos.1 + dir.1) as usize] != Symbol::Obstacle {
					pos.0 += dir.0;
					pos.1 += dir.1;
				}
				else {
					dir = next_dir(dir);
				}
			}

			mat[y][x] = Symbol::Free;
		}
	}
	println!("{}", count);
}
