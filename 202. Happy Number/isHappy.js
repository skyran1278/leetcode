/**
 * @param {number} n
 * @return {boolean}
 */
const isHappy = (n) => {
  const squares = {
    0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25, 6: 36, 7: 49, 8: 64, 9: 81,
  };
  const seen = {};
  let happy = n;
  while (!seen[happy]) {
    seen[happy] = true;
    const s = happy.toString(10);
    happy = s.split('').reduce((sum, v) => sum + squares[v], 0);
    if (happy === 1) return true;
  }
  return false;
  // const happy = (n) => {
  //   if (n === 1) return true;
  //   if (seen[n]) return false;
  //   seen[n] = true;
  //   const s = n.toString(10);
  //   return happy(s.split('').reduce((sum, v) => sum + squares[v], 0));
  // };

  // return happy(n);
};

console.log(isHappy(19));
