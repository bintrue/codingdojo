package color;

use strict;
my $defaultColor = "\033[00;00m";
my $green="\033[00;32m";
my $yellow="\033[00;33m";
my $red="\033[00;31m";

sub ok {
  return colorize( $green, @_ );
}


sub nok {
  return colorize( $red, @_ );
}


sub emph {
  return colorize( $yellow, @_ );
}


sub colorize {
  my $color = shift;
  my $message = shift;
  return $color . $message . $defaultColor;
}

1;

