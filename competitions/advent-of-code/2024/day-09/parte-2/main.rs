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

	let mut ri1 = (mem.len() - 1) as isize;
	let mut li1 = ri1;
	while li1 >= 0 && ri1 >= 0 {
		if mem[ri1 as usize] == -1 {
			ri1 -= 1;
		}
		else if li1 > ri1 {
			li1 = ri1;
		}
		else if mem[ri1 as usize] == mem[li1 as usize]{
			li1 -= 1;
		}
		else {
			let size1 = ri1 - li1;

			let mut li2 = 0 as isize;
			let mut ri2 = li2;
			while li2 < li1 && ri2 < ri1 {
				if mem[li2 as usize] != -1 {
					li2 += 1;
				}
				else if li2 > ri2 {
					ri2 = li2;
				}
				else if mem[li2 as usize] == mem[ri2 as usize]{
					ri2 += 1;
				}
				else {
					let size2 = ri2 - li2;

					if size1 <= size2 {
						for i in 0..size1 {
							println!("{} => {} | {} => {}", ri1 - i, li2 + i, mem[(ri1 - i) as usize], mem[(li2 + i) as usize]);
							mem[(li2 + i) as usize] = mem[(ri1 - i) as usize];
							mem[(ri1 - i) as usize] = -1;
						}
						break;
					}

					li2 = ri2;
				}
			}

			ri1 = li1;
		}
	}

	let mut sum = 0;
	for (i, n) in mem.into_iter().enumerate() {
		if n == -1 {
			continue;
		}
		sum += i * n as usize;
	}

	println!("{}", sum);
}
