

pub fn prison_after_n_days(mut cells: Vec<i32>, n: i32) -> Vec<i32> {
    let mut val: u8 = 0;
    let getval = |val: u8, i: u8| -> u8	{   val&(1<<i)	};
    let setval = |val: u8, i: u8| -> u8 {   val|(1<<i)	};
    for i in 0..8{
        if cells[7-i] == 1{
            val = setval(val, i as u8);
        }
    }
    let mut v: Vec<u8> = Vec::new();
    v.push(val);
    for t in 0..n{
        let mut tmp = 0;
        let mut val1: u8 = 0;
        for i in (1..7).rev(){
            let lt = getval(val, i+1)>>(i+1);
            let rt = getval(val, i-1)>>(i-1);
            if lt == rt{
                val1 |= (1<<i);
            }
        }
        val = val1;
        if val == v[0]{
            break;
        }
        v.push(val);
    }

    println!("cycle len = {}", v.len());
    println!("{:#010b}", v[(n%v.len() as i32) as usize]);
    cells
}

fn main(){
    let mut test1: Vec<i32> = vec![0,1,0,1,1,0,0,1];
    let mut cells: Vec<i32> = vec![1,0,0,1,0,0,1,0];
    let N: i32 = 16;
    println!("{:?}", prison_after_n_days(test1, N));
}
