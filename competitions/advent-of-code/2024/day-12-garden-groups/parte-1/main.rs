use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

struct Region {
	ar: i64,
	per: i64,
}

struct Plant {
	typ: char,
	reg: Option<usize>,
}

fn pos_reg(mat: &Vec<Vec<Plant>>, y: isize, x: isize) -> Option<usize> {
	if y <= -1 || y >= mat.len() as isize || x <= -1 || x >= mat[0].len() as isize {
		return Some(usize::MAX);
	}
	mat[y as usize][x as usize].reg
}

fn pos_typ(mat: &Vec<Vec<Plant>>, y: isize, x: isize) -> char {
	if y <= -1 || y >= mat.len() as isize || x <= -1 || x >= mat[0].len() as isize {
		return ' ';
	}
	mat[y as usize][x as usize].typ
}

fn dfs(mat: &mut Vec<Vec<Plant>>, regs: &mut Vec<Region>, y: isize, x: isize) {
	let movs = [(0, 1), (-1, 0), (0, -1), (1, 0)];
	for mov in movs {
		if pos_reg(mat, y + mov.0, x + mov.1) == pos_reg(mat, y, x) {
			continue;
		}
		if pos_typ(mat, y + mov.0, x + mov.1) != pos_typ(mat, y, x) {
			regs.last_mut().unwrap().per += 1;
			continue;
		}
		mat[(y + mov.0) as usize][(x + mov.1) as usize].reg = Some(regs.len() - 1);
		regs.last_mut().unwrap().ar += 1;
		dfs(mat, regs, y + mov.0, x + mov.1);
	}
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut mat = Vec::<Vec<Plant>>::new();
	for line in reader.lines() {
		let line = line.unwrap();
		mat.push(line.chars().map(|c| Plant { typ: c, reg: None, }).collect::<Vec<Plant>>());
	}

	let mut regs = Vec::<Region>::new();
	for y in 0..mat.len() {
		for x in 0..mat[y].len() {
			if mat[y][x].reg == None {
				regs.push(Region { ar: 1, per: 0, });
				mat[y][x].reg = Some(regs.len() - 1);
				dfs(&mut mat, &mut regs, y as isize, x as isize);
			}
		}
	}

	let mut sum = 0;
	for reg in regs {
		sum += reg.ar * reg.per;
	}

	println!("{}", sum);
}
