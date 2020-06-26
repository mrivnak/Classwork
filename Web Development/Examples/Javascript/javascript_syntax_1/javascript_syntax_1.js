var data = [90, 80, 96, 92, 100]
var sum = 0, average = 0;

for (var i = 0; i < data.length; i++) {
    sum += data[i];
}

average = sum/data.length;
console.log("The sum is: " + sum + "; The average is: " + average);