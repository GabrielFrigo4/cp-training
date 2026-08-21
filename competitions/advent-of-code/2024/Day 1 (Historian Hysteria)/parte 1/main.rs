use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut vec1 = Vec::<i32>::new();
	let mut vec2 = Vec::<i32>::new();

	for line in reader.lines() {
		let line = line.unwrap();
		let parts = line.split("   ").collect::<Vec<&str>>();
		let numb1 = parts[0].parse::<i32>().unwrap();
		let numb2 = parts[1].parse::<i32>().unwrap();
		vec1.push(numb1);
		vec2.push(numb2);
	}

	vec1.sort();
	vec2.sort();

	if vec1.len() != vec2.len() {
		panic!("Diferent sizes");
	}

	let mut dif = 0;
	for i in 0..vec1.len() {
		dif += (vec1[i] - vec2[i]).abs();
	}
	println!("{}", dif);
}
