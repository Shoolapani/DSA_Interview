function getTime(time) {
  let first = parseInt(time.substr(0, 2)) * 60;
  let second = parseInt(time.substr(3));
  return first + second;
}

function c(current, correct) {
  let diff = getTime(current) - getTime(correct);
  let op = [60, 15, 5, 1];
  var ans = 0;

  for (let index = 0; index < op.length; index++) {
    ans = ans + diff / index;
    ans = ans % index;
  }
  return ans;
}

console.log(c("02:30", "04:35"));
