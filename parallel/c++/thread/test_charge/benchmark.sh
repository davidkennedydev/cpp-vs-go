dataset=''

function measuring() {
  export dataset=$1
}

function measure() {
  local stats=$2.stat
  sudo perf stat -e cycles,cpu-clock $1 2> $stats
  cat $stats
  cycles=`cat $stats | grep -oP '(?<=^).*(?=cycles)' | sed 's/,//g' | sed 's/ //g'`
  export cpu_clock=`cat $stats | grep -oP '(?<=^).*(?=cpu-clock)' | sed 's/ //g'`
  echo $2 $cycles >> $dataset.cycles.measures
  echo $2 $cpu_clock >> $dataset.cpu_clock.measures
  rm $stats
}

source $1

gnuplot -p <<-EOFMarker
  set title "Cycle consumption"
  set ylabel "Hardware cycles"
  set xlabel "threads"
  plot "$dataset.cycles.measures" smooth unique title "$dataset"
  set term png
  set output "cycles.png"
  replot
EOFMarker

gnuplot -p <<-EOFMarker
  set title "Clock consumption"
  set ylabel "Software clock"
  set xlabel "threads"
  plot "$dataset.cpu_clock.measures" smooth unique title "$dataset"
  set term png
  set output "cpu_clock.png"
  replot
EOFMarker
