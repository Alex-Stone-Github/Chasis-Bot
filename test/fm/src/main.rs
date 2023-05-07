use std::collections::{HashSet, VecDeque};

fn main() {
    println!("Hello, world!");
}

trait Subsystem {}
trait Command {
    fn requirements(&self) -> std::collections::HashSet<Box<dyn Subsystem>>;
    fn is_done(&self) -> bool {
        false
    }
    fn is_interruptable(&self) -> bool {
        false
    }

    fn init(&mut self) {}
    fn execute(&mut self) {}
    fn end(&mut self, interupted: bool) {}
}

struct CommandScheduler {
    registered_subsystems: HashSet<Box<dyn Subsystem>>,
    command_queue: VecDeque<Box<dyn Command>>,
    running_commands: HashSet<Box<dyn Command>>,
}
impl CommandScheduler {
    fn schdule(&mut self, command: Box<dyn Command>) {
        self.command_queue.push_back(command);
    }
    fn run(&mut self) {}
}
