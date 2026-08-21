use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::collections::{HashMap, HashSet};

fn valid_pos(x: isize, y: isize, width: isize, height: isize) -> bool {
	return x > -1 && x < width && y > -1 && y < height;
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);
	let height = reader.lines().count() as isize;

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);
	let width = reader.lines().map(|x| x.unwrap()).collect::<Vec<String>>()[0].len() as isize;

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut antennas = HashMap::<char, Vec<(isize, isize)>>::new();
	for (y, line) in reader.lines().enumerate() {
		let line = line.unwrap();
		for (x, c) in line.chars().enumerate() {
			if c == '.' {
				continue;
			}
			if !antennas.contains_key(&c) {
				antennas.insert(c, Vec::<(isize, isize)>::new());
			}
			antennas.get_mut(&c).unwrap().push((y as isize, x as isize));
		}
	}

	let mut antinodes = HashSet::<(isize, isize)>::new();
	for list in antennas.values() {
		for i in 0..list.len() {
			for e in (i + 1)..list.len() {
				let dy = list[i].0 - list[e].0;
				let dx = list[i].1 - list[e].1;

				if valid_pos(list[i].1 + dx, list[i].0 + dy, width, height) {
					antinodes.insert((list[i].0 + dy, list[i].1 + dx));
				}
				if valid_pos(list[e].1 - dx, list[e].0 - dy, width, height) {
					antinodes.insert((list[e].0 - dy, list[e].1 - dx));
				}
			}
		}
	}

	println!("{}", antinodes.len());
}
