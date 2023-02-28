// Given a string only containing a/e/i/o/u, e.g. aeiaaioooaauuaeiu.
// Design an algorithm to find out the longest char orders in the order of a/e/i/o/u.
// E.g. the example input should output aeiiooouuu
const solved = (str) => {
  const tracks = [];
  const arr = str.split("");
  backtrack(arr, [], tracks);

  return tracks.reduce((longestChar, value) => {
    return longestChar.length < value.length ? value : longestChar;
  }, "");
};

/**
 *
 * @param {Array<String>} arr
 * @param {Array<String>} track
 * @param {Array<String>} tracks
 */
const backtrack = (rest, track, tracks) => {
  const lastChar = track[track.length - 1];

  for (let i = 0; i < rest.length; i++) {
    if (rest[i] < lastChar) continue;
    track.push(rest[i]);
    backtrack(rest.slice(i + 1), track, tracks);
    track.pop();
  }

  tracks.push(track.join(""));
};

console.log(solved("aeiaouaaaa") === "aaaaaa");
console.log(solved("aeiaouaaa") === "aeiou");
console.log(solved("aeiaaioooaauuaeiu") === "aeiiooouuu");
