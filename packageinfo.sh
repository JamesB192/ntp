# version=Protocol.Major.Minor
# odd minor numbers are for -dev, even minor numbers are for -stable
proto=4
major=2
minor=2
version=${proto}.${major}.${minor}
# Point.  3 cases:
# - Numeric values increment
# - empty 'increments' to 1
# - NEW (for example) 'increments' to empty
point=NEW
# Special.  Normally unused.  A suffix.
#special=ag
special=
# ReleaseCandidate. 'yes' or 'no'.
#releasecandidate=yes
releasecandidate=no
# ChangeLog tag
CLTAG=NTP_4_2_0
