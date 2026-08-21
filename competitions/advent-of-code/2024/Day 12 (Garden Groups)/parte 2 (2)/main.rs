use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

struct Region {
	ar: i64,
	si: i64,
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
	let mut count = 0;
	for mov in movs {
		if pos_reg(mat, y + mov.0, x + mov.1) == pos_reg(mat, y, x) {
			continue;
		}
		if pos_typ(mat, y + mov.0, x + mov.1) != pos_typ(mat, y, x) {
			count += 1;
			continue;
		}
		mat[(y + mov.0) as usize][(x + mov.1) as usize].reg = Some(regs.len() - 1);
		regs.last_mut().unwrap().ar += 1;
		dfs(mat, regs, y + mov.0, x + mov.1);
	}

	let p0 = pos_typ(mat, y + movs[0].0, x + movs[0].1) == pos_typ(mat, y, x);
	let p1 = pos_typ(mat, y + movs[1].0, x + movs[1].1) == pos_typ(mat, y, x);
	let p2 = pos_typ(mat, y + movs[2].0, x + movs[2].1) == pos_typ(mat, y, x);
	let p3 = pos_typ(mat, y + movs[3].0, x + movs[3].1) == pos_typ(mat, y, x);
	let p01 = pos_typ(mat, y + movs[0].0 + movs[1].0, x + movs[0].1 + movs[1].1) == pos_typ(mat, y, x);
	let p12 = pos_typ(mat, y + movs[1].0 + movs[2].0, x + movs[1].1 + movs[2].1) == pos_typ(mat, y, x);
	let p23 = pos_typ(mat, y + movs[2].0 + movs[3].0, x + movs[2].1 + movs[3].1) == pos_typ(mat, y, x);
	let p30 = pos_typ(mat, y + movs[3].0 + movs[0].0, x + movs[3].1 + movs[0].1) == pos_typ(mat, y, x);
	if p0 && p1 && !p01 {
		regs.last_mut().unwrap().si += 1;
	}
	if p1 && p2 && !p12 {
		regs.last_mut().unwrap().si += 1;
	}
	if p2 && p3 && !p23 {
		regs.last_mut().unwrap().si += 1;
	}
	if p3 && p0 && !p30 {
		regs.last_mut().unwrap().si += 1;
	}

	match count {
		4 => regs.last_mut().unwrap().si += 4,
		3 => regs.last_mut().unwrap().si += 2,
		2 => {
			if !(p0 == p2 && p1 == p3) {
				regs.last_mut().unwrap().si += 1;
			}
		},
		_ => (),
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
				regs.push(Region { ar: 1, si: 0, });
				mat[y][x].reg = Some(regs.len() - 1);
				dfs(&mut mat, &mut regs, y as isize, x as isize);
			}
		}
	}

	let mut sum = 0;
	for reg in regs {
		println!("{} {}", reg.ar, reg.si);
		sum += reg.ar * reg.si;
	}

	println!("{}", sum);
}
