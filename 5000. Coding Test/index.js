// Given a string only containing a/e/i/o/u, e.g. aeiaaioooaauuaeiu.
// Design an algorithm to find out the longest char orders in the order of a/e/i/o/u.
// E.g. the example input should output aeiiooouuu
const solved = (str) => {
  const tracks = [];
  const arr = str.split("");
  backtrack(arr, [], tracks);
  return tracks.reduce((longestChar, value) => {
    console.log(longestChar, value);
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
  if (rest.length == 0) {
    tracks.push(track.join(""));
    return;
  }
  for (let i = 0; i < rest.length; i++) {
    if (rest[i] < lastChar) continue;
    track.push(rest[i]);
    backtrack(rest.slice(i + 1), track, tracks);
    track.pop();
  }
};

const ans = solved("aeiaoua");

console.log(ans);
